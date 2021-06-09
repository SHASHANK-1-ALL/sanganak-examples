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

#include <chrono>
#include <fmt/format.h>
#include <fmt/core.h>
#include <mutex>
//#include <fmt/chrono.h>
#include <thread>
#include <list>

class ticker_listener_t
{
public:
virtual void update()=0;
virtual ~ticker_listener_t(){};
};

class ticker_t
{
    unsigned seconds;
    std::list<ticker_listener_t*> listeners;    
    std::mutex m;

    public:
    ticker_t(unsigned _sec):seconds(_sec)
    {    }
    ~ticker_t()
    {
        for(auto l: listeners)
        {
            if(l!=nullptr)
            {
                delete l;
            }
        }
    }
     void subscribe(ticker_listener_t* tl)
     {
         const std::lock_guard<std::mutex> l(m);
        listeners.push_back(tl);
     }
     void start()
     {
         unsigned count=20;
         fmt::print("Subroutine started\n");
         while(count>0)
         {
             fmt::print("Count is {}\n",count--);
             std::this_thread::sleep_for(std::chrono::seconds(seconds));
             std::lock_guard<std::mutex> l(m);
             for(auto l: listeners)
             {
                 l->update();
             }
         }
     }
};


class print_tick_t : public ticker_listener_t
{
   unsigned tick_number=0; 
   public:
   
   void update()
   {
       fmt::print("This is tick number {}\n", tick_number++);
   }
   ~print_tick_t(){}
};


class print_hello_on_tick_t : public ticker_listener_t
{
    public:
  void update()
  {
      fmt::print("Hello\n");
  }
  ~print_hello_on_tick_t(){}
};


int main()
{
    ticker_t t1(5);
    t1.subscribe(new print_tick_t());
//    t1.subscribe(new print_hello_on_tick_t());
//    t1.start();
auto f=[&](){t1.start();};
    std::thread thr1(f);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    t1.subscribe(new print_hello_on_tick_t());
  thr1.join();

    return 0;
}