#include <stdio.h>
#include<stdlib.h>

unsigned long long fact_cache[10]; //global scope

unsigned long long fact_functional(unsigned long long num)
{
    if(num==0) return 1;
    else return num*fact_functional(num-1);
}

unsigned long long fact_with_caching(unsigned long long num)
{
	if(fact_cache[num]==0)
	{
             unsigned long long result = num*fact_with_caching(num-1);
	     fact_cache[num]=result;
#ifdef DEBUG
	     printf("Computed value of fact(%llu) = %llu\n",num,result);
#endif	     

	     return result;

	}
	else
	{
#ifdef DEBUG
		printf("Returning already computed value of fact(%llu) = %llu \n",num,fact_cache[num]);
#endif
		return fact_cache[num];
	}
}


int main()
{
	unsigned long long num;
	fact_cache[0]=1;

	while(1)
	{
	scanf("%llu",&num);
	fact_with_caching(num);
	}
	return EXIT_SUCCESS;
}
