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

#ifndef __MYPAIR_H
#define __MYPAIR_H

#include <string>

class student_record_t
{
    std::string name;
    unsigned height;

    public:
    student_record_t()=default;
    student_record_t(const std::string&,const unsigned& );
    std::string getname();
    unsigned getheight();
};


#endif