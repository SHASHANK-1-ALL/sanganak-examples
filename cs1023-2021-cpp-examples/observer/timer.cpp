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
virtual void update(unsigned)=0;
virtual ~ticker_listener_t(){};
};

using listener_pairt=std::pair<ticker_listener_t*,bool>;

class ticker_t
{
    unsigned seconds;
    std::vector<listener_pairt> listeners;    
    std::mutex m;

    public:
    ticker_t(unsigned _sec):seconds(_sec)
    {    }
    ~ticker_t()
    {
        //std::shared_ptr
        for(auto& l: listeners)
        {
            if(l.first!=nullptr)
            {
                delete l.first;
            }
        }
    }
     unsigned subscribe(ticker_listener_t* tl)
     {
         const std::lock_guard<std::mutex> l(m);
         listener_pairt lp(tl,true);
        listeners.push_back(lp);
        return listeners.size()-1;

     }
     void unsubscribe(unsigned index)
     {
         const std::lock_guard<std::mutex> l(m);
         listeners[index].second=false;
     }
     void start()
     {
         constexpr unsigned maxcount=20;
         unsigned count=maxcount;
         fmt::print("Subroutine started\n");
         while(count>0)
         {
             count--;
      //       fmt::print("Count is {}\n",count--);
             std::this_thread::sleep_for(std::chrono::seconds(seconds));
             std::lock_guard<std::mutex> l(m);
             for(auto l: listeners)
             {
                 if(l.second)
                 { //launch asynchronously
                  l.first->update(maxcount-count);
                 }
             }
         }
     }
};


class print_tick_t : public ticker_listener_t
{
   unsigned tick_number=0; 
   public:
   
   void update(unsigned tick_count)
   {
       fmt::print("This is tick number {}\n", tick_count);
   }
   ~print_tick_t(){}
};


class print_hello_on_tick_t : public ticker_listener_t
{
    public:
  void update(unsigned tick_count)
  {
      fmt::print("Hello\n");
  }
  ~print_hello_on_tick_t(){}
};


int main()
{
    ticker_t t1(5);
   // t1.subscribe(new print_tick_t());
//    t1.subscribe(new print_hello_on_tick_t());
//    t1.start();
auto f=[&](){t1.start();};
    std::thread thr1(f);
    std::this_thread::sleep_for(std::chrono::seconds(15));
    unsigned ind1=t1.subscribe(new print_hello_on_tick_t());

    std::this_thread::sleep_for(std::chrono::seconds(15));
    unsigned ind2=t1.subscribe(new print_tick_t());
    std::this_thread::sleep_for(std::chrono::seconds(15));
    t1.unsubscribe(ind1);
  thr1.join();

    return 0;
}
