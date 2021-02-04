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

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	f=fopen("newfile.txt","w");
#if 0
	int a=5;
	int b=10;
	if(f==NULL)
	{
		printf("Could not open file\n");
	}	
	else
	{
		int o1=fprintf(f,"File opening was successful\n");
		printf("%p\n",f);
		scanf("%d",&a);
		int o2=fprintf(f,"a : %d, b: %d, a+b : %d\n",a,b,a+b);
		printf("o1: %d, o2 : %d\n",o1,o2);
		printf("%p\n",f);
		fclose(f);
	}
#endif

	if(f==NULL) return 1;
	

	 fprintf(f,"5 10 15\n");
	fclose(f);


	return EXIT_SUCCESS;
}
