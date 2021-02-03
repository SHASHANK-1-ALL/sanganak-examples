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
