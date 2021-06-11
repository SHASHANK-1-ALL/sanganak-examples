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
#include <fmt/format.h>
#include <vector>
#include <memory>
#include <queue>
#include <algorithm>
#include <numeric>

class worker_t
{
	std::vector<unsigned> jobs;
	unsigned worker_id;
	public:
	worker_t()
	{
		static unsigned id=0;
		worker_id=++id;
	}
	void submit_job(unsigned j)
	{
		jobs.push_back(j);
	}
	void print_jobs()
	{
		fmt::print("ID : {} ::",worker_id);
		for(auto j : jobs)
		{
			fmt::print("{} ",j);

		}
		fmt::print("\n");
		size_t sz=jobs.size();
		auto sum=std::accumulate(jobs.begin(),jobs.end(),0);
		fmt::print("Total load : {}\n",sum);
		
	}
};

class scheduling_strategyt
{

public:
  virtual void schedule(const std::vector<unsigned>& jobs, std::vector<worker_t*>& workers ) = 0;
};

class rr_scheduling_strategyt : public scheduling_strategyt
{
	public:
	void schedule(const std::vector<unsigned>& jobs, std::vector<worker_t*>& workers)
	{
		size_t index=0;
		size_t sz = workers.size()-1;
		for(auto& j : jobs)
		{
		     workers[index]->submit_job(j);
		     index++;
		     if(index>sz) index=0;  
		}
	}
};


struct job_comparet
{
public:
// return true if a < b
bool operator()(const std::pair<unsigned,unsigned>& a, const std::pair<unsigned,unsigned>& b)
{
	return a.first > b.first;
}
};

class lb_scheduling_strategyt: public scheduling_strategyt
{
	public:
	void schedule(const std::vector<unsigned>& jobs, std::vector<worker_t*>& workers)
	{
		std::priority_queue<std::pair<unsigned,unsigned>,std::vector<std::pair<unsigned,unsigned>>,job_comparet> pq;
		size_t sz=workers.size()-1;
		for(unsigned i=0;i<=sz;i++)
		{
			pq.push(std::make_pair(0,i));			

		}
		for(auto& j : jobs)
		{
			auto p = pq.top();
			pq.pop();
			p.first+=j;
			workers[p.second]->submit_job(j);
			pq.push(p);
		}

	}

};


int main()
{
	std::vector<unsigned> jobs={34,54,3,89,9,2,4,1,99,32,432,3,5,7,4,9,2,1};
	std::vector<worker_t*> w;
	w.push_back(new worker_t());
	w.push_back(new worker_t());
	w.push_back(new worker_t());
	w.push_back(new worker_t());
	scheduling_strategyt* ss = new rr_scheduling_strategyt();
//	scheduling_strategyt* ss = new lb_scheduling_strategyt();
	ss->schedule(jobs,w);
	for(auto& ww: w)
	{
		ww->print_jobs();
	}
	return 0;
}