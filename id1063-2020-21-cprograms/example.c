#include <stdio.h>

int main()
{
	unsigned a=53;
	unsigned b;

	b=a=34;

	printf("%u %u\n",a++,++b);
	printf("%u\n",b);

	a = f1()+f2()+f3();
	a = (a++) + ++a - --a + ++a;


	return 0;
}



