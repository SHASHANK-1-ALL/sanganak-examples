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



//comparision between std::cout, fmtlib and printf
// compile using:
//  g++ -o printing -O3 -I /path/to/fmtlib/include -L /path/to/dir/containing/libfmt.a printing.cpp -lfmt
#include <iostream>
#include <chrono>
#include <cstdio>
#include <fmt/core.h>

#define NUM_TIMES 100000
using myclock_t = std::chrono::high_resolution_clock;
using msduration_t = std::chrono::duration<double,std::milli>;

int main()
{

	auto start = myclock_t::now();

	for (unsigned i=0;i<NUM_TIMES;i++)
	{
		std::cout << "Hello World! How are you? " << i << std::endl;
	}

	auto mid1 = myclock_t::now();

	for(unsigned i=0;i<NUM_TIMES;i++)
	{
		fmt::print("Hello World! How are you? {}\n",i);
	}

	auto mid2 = myclock_t::now();

	for(unsigned i=0;i<NUM_TIMES;i++)
	{
		std::printf("Hello World! How are you?%u\n",i);
	}

	auto end = myclock_t::now();
	msduration_t first = mid1-start;
	msduration_t second=mid2-mid1;
	msduration_t third=end-mid2;

	fmt::print("Using std::cout {} milliseconds\n",first.count());
	fmt::print("Using fmtlib {} milliseconds\n",second.count());
	fmt::print("Using printf {} milliseconds\n",third.count());
	return 0;
	
}
