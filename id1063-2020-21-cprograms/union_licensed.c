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


struct _float_and_int_t
{
	float f;
	int i;
	char c;
};
typedef struct _float_and_int_t float_and_int_t;

union _float_or_int_t
{
	double d[10];
	float f;
	int i;
	char c;
};

typedef union _float_or_int_t floatint_t;

int main()
{
	floatint_t arr[10];

	for(unsigned i=0;i<10;i++)
	{
		if ((i&1)==0)
		{
			arr[i].i=i;
		}
		else
		{
			arr[i].f=(i+0.5);
		}
			
	}
	for(unsigned i=0;i<10;i++)
	{
		if ((i&1)==0)
		{
			printf("%u : %d\n",i,arr[i].i);
			printf("%u : %f\n",i,arr[i].f);
		}
		else
		{
			printf("%u : %f\n",i,arr[i].f);
		}
			
	}


	float_and_int_t fi={0.2,3};

	printf("Size of struct and union %lu %lu\n",sizeof(fi),sizeof(arr[0]));

	return EXIT_SUCCESS;
}
