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

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <limits>
#include <future>
#include <numeric>
#include <chrono>

#define SPLIT 8
#define VECSIZE 10000000

std::vector<std::vector<int> > global_v;
class uniform_int_randomt
{
private:
std::random_device rd;
std::default_random_engine re;
std::uniform_int_distribution<int> ud;
public:
uniform_int_randomt(int _lb=std::numeric_limits<int>::min(),
 int _ub=std::numeric_limits<int>::max()):re(rd()),ud(_lb,_ub)
 {
	 
 }

int next() { return ud(re);}
};

void gen_random_vector(std::vector<int>& v)
{
	uniform_int_randomt uir;
	size_t sz=VECSIZE;
	for(int i=0;i<sz;i++)
	{
		v.push_back(uir.next());
	}

}

int sum_up(unsigned int index)
{
	return std::accumulate(begin(global_v[index]),end(global_v[index]),0);
}
int mysum(int a, int b)
{ return a+b;}


int main()
{
	for(unsigned int i=0;i<10;i++)
	{
		global_v.emplace_back(std::vector<int>());
		gen_random_vector(global_v[i]);
	}

//	auto acc = [](std::vector<int>& v) { return std::accumulate(begin(v),end(v),0);};
// int foo(int a, int b) -->v= foo(3,4) --> synchronous call
// int foo(int a, int b) --> v (future) =async foo(3,4) --> asynchronous call
// task-based parallelism
// vector processing

/*
32-bit int
512-bit wide registers
ISA - Instruction Set Architecture
add eax
addv  
send()/receive()
x++;


for(unsigned i=0;i<100;i++)
   a[i]= b[i]+ c[i];

*/
std::vector<std::future<int>> vf;
std::vector<int> vi;
auto asynctime = std::chrono::system_clock::now();
	for(unsigned int i=0;i<SPLIT;i++)
	{
		vf.push_back(std::async(std::launch::async,sum_up,i));
	}
	for(unsigned int i=SPLIT;i<10;i++)
	{
		vi.push_back(sum_up(i));
	}
	for(unsigned int i=0;i<vi.size();i++)
	{
		std::cout << vi[i] << std::endl;
	}
	for(unsigned int i=0;i<SPLIT;i++)
	{
		std::cout << vf[i].get() << std::endl;
	}
	auto asyncstop = std::chrono::system_clock::now();
	auto asyncduration = std::chrono::duration_cast<std::chrono::nanoseconds>(asyncstop-asynctime);
	std::cout << "Async duration: " << asyncduration.count() << std::endl;
	auto seqtime = std::chrono::system_clock::now();
	std::vector<int> vis;
	for(unsigned int i=0;i<10;i++)
	{
		vis.push_back(sum_up(i));
	}

	for(unsigned int i=0;i<10;i++)
	{
		std::cout << vis[i] << std::endl;
	}
	auto seqstop = std::chrono::system_clock::now();
	auto seqduration=std::chrono::duration_cast<std::chrono::nanoseconds>(seqstop-seqtime);
	std::cout << "Seq duration: " << seqduration.count() << std::endl;
	return 0;
}