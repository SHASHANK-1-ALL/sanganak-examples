/*    Copyright (C) 2021  Saurabh Joshi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __THREAD_SAFE_Q_H
#define __THREAD_SAFE_Q_H


#include <mutex>
#include <queue>
#include <functional>
#include <utility>
#include <condition_variable>
#include <optional>
#include <thread>
#include <iostream>

class thread_safe_worklist_t
{

std::vector<std::function<void ()>> q;
std::mutex m;
std::condition_variable cv;
unsigned index=0;

public:

template <typename F, typename... Args>
void push(F fun,Args&&... args)
{
    std::lock_guard<std::mutex> guard(m);
    
    auto f = std::bind(std::forward<F>(fun),std::forward<Args>(args)...);
    q.emplace_back(std::function<void ()> ([f]{f();}));
    ((std::cout << args << ':'), ...);
    std::cout << std::endl;
   // cv.notify_all();
}

std::optional<std::function<void()>> get()
{
    std::lock_guard<std::mutex> guard(m);
 //   std::unique_lock<std::mutex> lk(m);
//    cv.wait(lk,[&,this](){return !this->q.empty();});
  //  std::function<void ()>& elem = q.front();
    if(index < q.size())
    {
        std::cout << "get_id: " << std::this_thread::get_id() << ":" << index << ":" << q.size() << std::endl;
       return q[index++]; 
    }

    return {};

}

size_t size()
{
    std::lock_guard<std::mutex> guard(m);
    return q.size();
}

bool empty()
{
    std::lock_guard<std::mutex> guard(m);
    return q.empty();
}

    
};

#endif