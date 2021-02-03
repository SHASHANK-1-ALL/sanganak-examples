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
