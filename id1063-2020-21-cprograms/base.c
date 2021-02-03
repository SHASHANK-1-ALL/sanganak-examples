#include <stdio.h>
#include <stdlib.h>

int main()
{

	unsigned num,base,index=0,a[32];
	printf("Enter the number: ");
	scanf("%u",&num);
	printf("Enter the base: ");
	scanf("%u",&base);

	while(num>0)
	{
		a[index++]=num%base;
		num/=base;
	}
	printf("\nThe number is base %u is : ",base);
	for(;index>0;index--)
	{
		if(a[index-1]>=10)
		{
			printf("%c",a[index-1]+87);
		}
		else
		{
			printf("%d",a[index-1]);
		}
	}
	printf("\n");
	return EXIT_SUCCESS;
}
