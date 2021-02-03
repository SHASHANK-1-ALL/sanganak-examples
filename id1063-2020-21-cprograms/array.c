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
