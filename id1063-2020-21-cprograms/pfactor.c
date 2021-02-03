#include <stdio.h>

void foo(unsigned num)
{
	for(unsigned j=2;_______;)
	{
		if(num%j) {j++;continue;}
		else {printf("%u ",j);_______;}

	}
}

int main()
{
	for(unsigned i=0;i<100;i++)
	{
		printf("\n %u : ",i);
		foo(i);
	}
	printf("\n");
}
