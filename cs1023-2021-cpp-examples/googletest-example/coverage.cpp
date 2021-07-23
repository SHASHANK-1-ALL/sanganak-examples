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

#include <limits.h>
#include <iostream>
#include <gtest/gtest.h>
//predicate coverage
// precondition: y > 0
#define P(U,W) std::cout << #U << ":" << U << "," << #W << ":" << W << std::endl; 
//100% input state coverage
// x+y mod (2 raised to 32) GF(p)
//groups, rings, fields (abstract algebra)
void swap(int &x, int &y)
{
	P(x,y);
	x=x+y;
			
	P(x,y);
			
	y=x-y;
	P(x,y);
	x=x-y;
	P(x,y);

	x=x^y;
	y=x^y;
	x=x^y;
	
}



int foo(int x, int y)
{
#if 0
	int z;
	if(x>0) //else branch?
	{
		z=x+y;
	}
	return z;

// x=1,y=-1
//x=-1,y=1
// 100% branch coverage but only 50% path coverage
// input state coverage
// state coverage (program is a state-transition system) --> verification
int z;
	if(x>0)
	{
		z=x;
	}
	else {
		z=-x;
	}
	if(y>0)
	{
		z=z+y;
	}
	else{
		z=z-y;
	}
	

	return z;
#endif
 return x;
}


TEST(SWAP,swap1)
{
	int x=INT_MAX-1;
	int y=5;
	swap(x,y);
	EXPECT_EQ(x,5);
	EXPECT_EQ(y,INT_MAX-1);
}

#if 0
TEST(ADD,add2)
{
	EXPECT_GE(foo(-2,3),-2);	
}

TEST(ADD,add1)
{
	EXPECT_GE(foo(2,3),2);	
}
#endif

int main(int argc,char** argv)
    {
        testing::InitGoogleTest(&argc,argv);
        return RUN_ALL_TESTS();
    }
