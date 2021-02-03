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
#include <stdlib.h>

/* Write a program that takes two numbers n and r and prints n choose r */


unsigned long long factorial(unsigned long long num);
/*
 *  precondition: n > 0 and n >= r and (value of n and r small enough to avoid overflow)
 *
 *  postcondition: return the value (n \choose r)
 *
 *
 */
unsigned long long compute_n_choose_r(unsigned long long  n, unsigned long long r) //signature of a function
{
   unsigned long long n_fact = factorial(n); // num = n;
   unsigned long long r_fact = factorial(r);
   unsigned long long n_minus_r_fact = factorial(n-r);

   return n_fact / ((r_fact)*(n_minus_r_fact));

}


/*
 * precondition : num small enough not to overflow
 *
 * postcondition: return factorial of num
 */
unsigned long long factorial(unsigned long long num)
{
	if (num==0)
	{
		return 1;
	}
	else
	{
		unsigned prod=1;
		for(unsigned u=1;u<=num;u++)
		{
			prod*=u;
		}
		return prod;
	}
}

int main()
{

	unsigned n, r;

	printf("Enter n:\n");
	scanf("%u",&n);
	printf("Enter r:\n");
	scanf("%u",&r);
        
	printf("Value of n choose r is: %llu\n",compute_n_choose_r(n,r));

	return EXIT_SUCCESS;
}
