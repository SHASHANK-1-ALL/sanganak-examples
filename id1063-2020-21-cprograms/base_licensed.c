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

int main()
{

	unsigned num,base,index=0,a[32];
	printf("Enter the number: ");
	scanf("%u",&num);
	printf("Enter the base: ");
	scanf("%u",&base);

	while(num>0)
	{
		a[index++]=num%base;
		num/=base;
	}
	printf("\nThe number is base %u is : ",base);
	for(;index>0;index--)
	{
		if(a[index-1]>=10)
		{
			printf("%c",a[index-1]+87);
		}
		else
		{
			printf("%d",a[index-1]);
		}
	}
	printf("\n");
	return EXIT_SUCCESS;
}
