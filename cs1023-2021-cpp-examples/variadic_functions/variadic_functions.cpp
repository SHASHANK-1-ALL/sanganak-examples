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
#include <utility>

template <typename F, typename... Args>
void wrapper(F fun,Args&&...args) requires {fun(std::forward<Args>(args)...)}wchar_t
{
    fun(std::forward<Args>(args)...);
}


void print(int a, int b)
{
    std::cout << a << ":" << b << std::endl;
}

void compute_sum(int a, int b)
{
    std:: cout << a+b << std::endl;
}

int main()
{
    wrapper(print,1,2);
    wrapper(compute_sum,2,3);

    return 0;
}