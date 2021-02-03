#include <stdio.h>

enum color_t {GREEN,BLUE=0};
enum nicecolor_t {RED, PINK};

int main()
	
{
	char f=GREEN;
	char a=BLUE;
//	char f1=f>>a;
	printf("%d : %d\n",f,a);
	return 0;
}
