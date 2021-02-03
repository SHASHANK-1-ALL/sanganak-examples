#include <stdio.h>

/*
 * Inputs : a, b
 *
 * Output : mysum, myprod
 *
 */
void myadd(const int* a, const int* b, int* mysum, int* myprod)
{
#ifdef DEBUG
	printf("Inside myadd");
	printf("%p : %p : %p : %p\n",mysum,myprod,&mysum,&myprod);
#endif
	(*mysum)= (*a)+(*b);
	(*myprod) = (*a) * (*b);
	
}

int main()
{
	int a=5;
	int b=7;
	int sum;
	int tmp[10];
	int prod;
	printf("%d: %d : %p : %p \n",sum,prod,&sum,&prod);
	myadd(&a,&b,&sum,&prod);
	printf("%d : %d : %d : %d\n",a,b,sum,prod);
	return 0;
}
