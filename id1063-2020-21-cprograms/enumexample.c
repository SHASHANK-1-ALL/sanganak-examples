#include <stdio.h>


#if 0
/* This function acts as an example of switch-case statement */
#endif
int main()
{
	enum weekday_t {MONDAY,TUESDAY,WEDNESDAY=10,THURSDAY=10,FRIDAY=34,SATURDAY,SUNDAY};
	enum color_t {RED,GREEN,BLUE,INDIGO};


	enum weekday_t w;
	enum color_t c;


	w=WEDNESDAY ;
	c=BLUE+INDIGO;

	float f = 3.0;



#if 0
 	switch(f)
	{
		case 5.0 : printf("float value is 5.0\n");break;
		default: printf("Where am I?\n"); break;
	}
#endif
	//variable in a switch has to have an integral type
	switch(w)
	{
		case SATURDAY: printf("SATURDAY is part of a weekend\n");
		//	       break;
		case MONDAY: printf("MONDAY is a weekday\n"); break;
		case TUESDAY: printf("TUESDAY is a weekday\n"); break;
		case WEDNESDAY: printf("WEDNESDAY is a weekday\n"); 
//		case THURSDAY: printf("THURSDAY is a weekday\n");
			       break;
		case FRIDAY: printf("FRIDAY is a weekday\n");
			     break;
		case SUNDAY: printf("SUNDAY is part of a weekend\n");
			     break;
	
		default: printf("Are we on Earth?\n");
	}




	printf("weekday is %d, color is %d\n",w,c);
	printf("TUESDAY int value is %d\n",TUESDAY);
	printf("SATURDAY int value is %d\n",SATURDAY);

	return 0;
}
