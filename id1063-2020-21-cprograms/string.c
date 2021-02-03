#include <stdio.h>
#include <stdlib.h>

int main()
{

	char *weekdays[] = {"Sunday", "Monday" , "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	char myweekdays[][10]= {"Sunday", "Monday" , "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	unsigned u1, u2;

	0[myweekdays][0] = 65;
	u1 = weekdays[0][5];
//	u2 = weekdays[2][7];

	printf("%u :  %u\n",u1,u2);
	for(unsigned i=0;i<7;i++)
	{
		printf("%s\n",i[myweekdays]);
	}

	return EXIT_SUCCESS;



}
