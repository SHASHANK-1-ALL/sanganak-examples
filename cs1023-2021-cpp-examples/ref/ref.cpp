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

// Type your code here, or load an example.
#include <iostream>
#include <string>
#include <utility>


class sr_t
{
   std::string name;
   std::string address;
   // 5, "SDF", print_sr, a+b
   public:
   sr_t()=delete;
   sr_t(const sr_t&)=default; //copy constructor
   sr_t(sr_t&&)=default; //move constructor
   sr_t(std::string&& _name,std::string&& _address)
   {
       name=_name;
       address=_address;
   }
   
   const std::string& getname() const {return name;}
   const std::string& getaddress() const {return address;}
};

void print_sr(sr_t&& s)
{
    std::cout << s.getname() <<":" << s.getaddress() << std::endl;
    
    }

    int main()
{
    
    std::string somename="Sherlock";
    std::string someaddress="221B, baker street";
    sr_t sr(std::move(somename),std::move(someaddress));
   
    print_sr(std::move(sr));
    
    return 0;
}