/*    Copyright (C) 2020  Saurabh Joshi

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


#include <stdio.h>
#include<stdlib.h>

unsigned long long fact_cache[10]; //global scope

unsigned long long fact_functional(unsigned long long num)
{
    if(num==0) return 1;
    else return num*fact_functional(num-1);
}

unsigned long long fact_with_caching(unsigned long long num)
{
	if(fact_cache[num]==0)
	{
             unsigned long long result = num*fact_with_caching(num-1);
	     fact_cache[num]=result;
#ifdef DEBUG
	     printf("Computed value of fact(%llu) = %llu\n",num,result);
#endif	     

	     return result;

	}
	else
	{
#ifdef DEBUG
		printf("Returning already computed value of fact(%llu) = %llu \n",num,fact_cache[num]);
#endif
		return fact_cache[num];
	}
}


int main()
{
	unsigned long long num;
	fact_cache[0]=1;

	while(1)
	{
	scanf("%llu",&num);
	fact_with_caching(num);
	}
	return EXIT_SUCCESS;
}
