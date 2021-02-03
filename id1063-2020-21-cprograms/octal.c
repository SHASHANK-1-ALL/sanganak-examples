#include <stdio.h>
#include <limits.h>

int  is_palindrome(unsigned num)
{
	unsigned l=1<<(________);
	unsigned r=1;

	for(;l>r;l>>=1,r<<=1)
	{
		if(_________) return 0;
	}
	return 1;
}

int main()
{
	for(unsigned i=0x000ff000;i!=UINT_MAX;i++)
	{
		if(is_palindrome(i))
		{
			printf("%u is a palindrome\n",i);
		}
	}

	return 0;
}
