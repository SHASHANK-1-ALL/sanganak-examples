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


int sum(int arr[][2],int rows,int cols)
{
	int sum=0;
    for(unsigned i=0;i<rows;i++)
    {
	    for(unsigned j=0;j<cols;j++)
	    {
		    sum+=arr[i][j];
	    }
    }
    return sum;
}

int main()
{

	int arr[2][2]={{1,2},{2,3}};

	printf("Sum is : %d\n",sum(arr,2,2));

	return EXIT_SUCCESS;
}
