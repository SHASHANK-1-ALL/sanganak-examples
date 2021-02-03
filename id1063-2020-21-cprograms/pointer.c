#include <stdio.h>
#include <stdlib.h>


struct _something_t
{

	int a;
	char b;
};

typedef struct _something_t something_t;

int main()
{
	something_t a[2] = {{3,'a'},{53,'b'}};	

	something_t *p = &(a[0]);

	printf("%d : %c : %p\n",p->a, p->b, (p));
	printf("%d : %c : %p\n",p[1].a, p[1].b, p+1);
	return EXIT_SUCCESS;
}
