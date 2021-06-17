
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




#include <string>
#include <vector>
#include <iostream>
#include <fmt/format.h>
// Reuse of code
// Generic Programming or Templates
// state design pattern


/**
 * @brief 
 * 
 *   class state_t
 *   {
 *      virtual state_t* next(input)
 * 
 * 
 *   }
 * 
 * 
 *    class state_1t : public state_t
 *    {
 *       next(input) { if(input==someting) return state_2t
 *                      else return state_3t }
 *    }
 * 
 */


enum class blood_type_t {APOSITIVE, ANEGATIVE,ABPOSITIVE, ABNEGATIVE, BPOSITIVE, BNEGATIVE,
OPOSITIVE, ONEGATIVE};
class student_record_t
{

public:
std::string name;
unsigned height;
blood_type_t bt;
unsigned weight;

student_record_t(std::string&& str,unsigned h,unsigned w,blood_type_t b): name(str),
         height(h),weight(w),bt(b) {}
void print_record()
{
	fmt::print("{}:{}:{}:{}\n",name,height,weight,static_cast<int>(bt));
}

};

class record_sorter_t
{
  public:
  //compare should return true if a > b
  virtual ~record_sorter_t() {}
  virtual bool compare(const student_record_t& a, const student_record_t& b) = 0;
  void sort_student_records(std::vector<student_record_t>& sr)
  {

	  	size_t size=sr.size();
		  for(unsigned i=0;i<size-1;i++)
		  {
			  for(unsigned j=i+1;j<size;j++)
			  {
				  if(compare(sr[i],sr[j]))
				  {
					  std::swap(sr[i],sr[j]);
				  }
			  }
		  }

  }
};


class height_sorter_t : public record_sorter_t
{
	public:
	bool compare(const student_record_t& a, const student_record_t&b)
	{
		return a.height > b.height;
	}
};


class weight_sorter_t : public record_sorter_t{
public:

bool compare(const student_record_t& a, const student_record_t&b)
	{
		return a.weight > b.weight;
	}
};

int main()
{
  std::vector<student_record_t> v;
	v.emplace_back("Alice",165,65,blood_type_t::ANEGATIVE);
	v.emplace_back("Bob",170,50,blood_type_t::BNEGATIVE);
	v.emplace_back("Charlie",180,55,blood_type_t::OPOSITIVE);
	v.emplace_back("Derick",175,60,blood_type_t::ABPOSITIVE);
  

	 for(auto &e : v)
	 {
		 e.print_record();
	 }
	 record_sorter_t* rs = new weight_sorter_t();
	 rs->sort_student_records(v);
	for(auto &e : v)
	 {
		 e.print_record();
	 }

	 return 0;

};
/**
 * @brief 
 * 
 * common_logic
 *    initialize();
 *     if(character==villager)
 *      {
 *          character->do_villager_stuff(0)
 *       }
 *    else if(character==soldier)
 *       {
 *           soldier specific things
 *      }
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */







