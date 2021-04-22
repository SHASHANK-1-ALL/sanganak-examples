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
#include <assert.h>
#include <array>
#include <optional>
#include <stdexcept>
#include <iostream>

template <typename T,std::size_t SZ>
class stack_t
{

std::array<T,SZ> arr;
std::size_t index=0;

public:

//T top() 
#if 0
bool push(const T elem) 
{
    if(index==SZ)
    {
        return false;
    }
    arr[index]=elem;
    ++index;
    return true;
}
#endif
void push(const T elem) noexcept
{
  arr.at(index)=elem; 
  ++index;
}
std::optional<T> top() const
{
    if(index==0)
    {
        return {};
    }

    auto tmp= arr[index-1];
    return tmp;
}

bool pop()
{
    if(index==0){
        return false;
    }
    index--;
    return true;
}

};


int foo()
{
    constexpr int testarray[] = {2,3,-1,4,-90,23,100};

    constexpr std::size_t arrsz = sizeof(testarray)/sizeof(int);
    stack_t<int,arrsz-2> s;

    auto v = s.top();
    assert(v.has_value()==false);

try{
    for(unsigned i=0;i<arrsz;i++)
    {
    s.push(testarray[i]);
    std::cout << testarray[i] << "pushed successfully" << std::endl;

    }
     }
    /*catch(std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "Exception thrown..terminating program" << std::endl;

    }*/  
    catch (std::bad_alloc& e)
    {
        std::cout << "generic exception" << std::endl;
    }
    catch(std::bad_cast& e)
    {std::cout << "Graceful termination" << std::endl;}

    return 0;
}

int main()
{
    try{
        foo();
    }
    catch(std::exception& e)
    {
        std::cout << "caught an exception in main" << std::endl;
    }
    //std::cout << "inbetween try-catch" << std::endl;
    catch(std::out_of_range& e)
    {
        std::cout << "out of range caught in main" << std::endl;
    }
    std::cout << "Ending main" << std::endl;
    return 0;
}