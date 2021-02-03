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
#include <inttypes.h>
#include <limits.h>


int max(int a, int b)
{
	int result;
	if(a>b) result=a;
	else result=b;	

	return result;
}

int min(int a,int b)
{
	if(a>b) return b;
	return a;

}

int main()
{

	int (*fun)(int,int)=max;
	int a=5;
	int b=10;
	printf("%d\n",fun(a,b));
	fun=min;

	printf("%d\n",fun(a,b));
	return EXIT_SUCCESS;
}
