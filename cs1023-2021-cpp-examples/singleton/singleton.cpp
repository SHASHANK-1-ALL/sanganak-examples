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


#include <iostream>
#include <chrono>
#include <thread>

template <typename T>
class singleton_t
{

singleton_t() {} //private

//static singleton_t* instance;

T _data;

public:

singleton_t(const singleton_t&)=delete;
void operator=(singleton_t&)=delete;

void set_data(T d)
{
    _data = d;
}

T get_data()
{
    return _data;
}

static singleton_t& get_instance()
{
    static singleton_t instance;
     std::cout << &instance << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    /*if(instance==nullptr)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        instance = new singleton_t;
        std::cout << "new instance created: " << instance << std::endl;
    }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        */
    return instance;
}


};

//template <> singleton_t<int>* singleton_t<int>::instance = nullptr;

int main()
{

    std::thread t([](){ singleton_t <int>* s1 = &singleton_t<int>::get_instance();
                         s1->set_data(30); std::cout << s1->get_data() << s1 << std::endl; });

    singleton_t<int>* s = &singleton_t<int>::get_instance();

    //s->set_data(10);
    std::cout << s->get_data() << s << std::endl;
    singleton_t<int>* p = s;
    p->set_data(40);
    std::cout<< p->get_data() << ":" << s->get_data() << std::endl;
    t.join();
    return 0;
}