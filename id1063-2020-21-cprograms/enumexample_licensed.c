/*    Copyright (C) 2020  Saurabh Joshi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


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
