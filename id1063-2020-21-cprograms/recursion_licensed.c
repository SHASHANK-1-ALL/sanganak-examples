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

unsigned long long factorial(unsigned long long num)
{
	if(num==0) return 1;
	return num*factorial(num-1);
}



int main()
{
	unsigned long long n;
	scanf("%llu",&n);
	printf("Value of the factorial is: %llu\n",factorial(n));
	return EXIT_SUCCESS;
}
