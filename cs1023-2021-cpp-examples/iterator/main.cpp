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

#include "mylist.h"
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>

struct lessthanzero_t
{
  char operator()(const auto& x) {return 'c';}
} ltz;

bool ltzf(const auto& x) {return x<0;}

int main()
{

    int arr[] = {4,32,54,-9,0,0,3,2,-90,123123,-451212};
    constexpr size_t asize=sizeof(arr)/sizeof(int);
    mylist_t<int> l;
    for(unsigned i=0;i<asize;i++)
    {
            l.push_front(arr[i]);

    }
    std::cout << "pushed" << std::endl;
    std::cout << "size of list is " << l.size() << std::endl;
   // auto foo = [](const auto& x){return x;};
    //std::cout << std::count_if(l.begin(),l.end(),[](const auto& x){return x<0;}) << std::endl;
    std::cout << std::count_if(l.begin(),l.end(),ltz) << std::endl;
    std::fill(l.begin(),l.end(),-1);
    std::cout << std::count_if(l.begin(),l.end(),[](const auto& x){return x<0;}) << std::endl;
    //std::for_each(arr,arr+asize,);
    return EXIT_SUCCESS;
}

