#include <stdio.h>

int main()
{
	int a = 5;
	unsigned long long p = &a;

	printf("%d: %llx : %p \n",a,p, &a);
	return 0;
}
