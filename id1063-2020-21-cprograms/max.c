/* Write a program that filters out all the negative numbers */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{

	int num[SIZE];

	for(unsigned i =0;i<SIZE;i++)
	{
		scanf("%d",&num[i]);
	}

	for(unsigned i = 0 ; i < SIZE ;i++)
	{

		if(num[i] < 0) continue; 

		printf("%d ",num[i]);

	}

	printf("\n");

	
	return EXIT_SUCCESS;
}


