
#include <stdio.h>

int foo(int a,int b)
{
	return a+b;
}
int bar(int a,int b)
{
	return a*b;
}


int reduce(int (*fun)(int,int),int a[],int asize,int init_value)
{
	int result=init_value;
	for(unsigned i=0;i<asize;i++)
	{
		result=fun(result,a[i]);
	}
	return result;
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",reduce(foo,a,10,0));
	printf("%d\n",reduce(bar,a,10,1));
	return 0;
}
