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
#include <array>
#include "student_record_t.h"

template <typename T1, typename T2>
class mypair
{
   public:
      mypair(const T1& _t1, const T2& _t2) {
          first = _t1;
          second = _t2;
      } 

    T1 getfirst() {return first;}
    T2 getsecond() {return second;}
    private:

    T1 first;
    T2 second;


};



int main()
{
    student_record_t sr("Alice",90);
    std::cout << sr.getname() << ":" << sr.getheight() << std::endl;

    mypair<student_record_t,unsigned> p(sr,40);

    std::cout << p.getfirst().getname() << ":" << p.getfirst().getheight() << ":" << p.getsecond() << std::endl;

    return 0;
}