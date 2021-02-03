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
#include <stdlib.h>


struct _point_t
{
	double x;
	double y;
};

typedef struct _point_t point_t;


void print_point(point_t p)
{
	printf("x = %lf : y=%lf\n",p.x,p.y);
}

void swap(point_t* p1, point_t* p2)
{
        point_t tmp;
	tmp.x = p1->x;
	tmp.y = p1->y;
	p1->x = p2->x;
	p1->y=p2->y;
	p2->x=tmp.x;
	p2->y=tmp.y;
}

void add_points(const point_t* p1, const point_t* p2, point_t *result)
{
	result->x = p1->x + p2->x;
	result->y = p1->y + p2->y;
//	p1->x = p1->x + p2->x;
}

int main()
{
       point_t points[5]={{35.4,75.6},{3.2,89.32},{2.3,98.34},{-0.89,2.3},{0,0}};
       point_t *ppoints[5];

 	const int i = 5;
	scanf("%d",&i);
	printf("%d\n",i);

       for(unsigned i=0;i<5;i++)
       {
	       ppoints[i]=&points[i];
       }

	printf("Before sorting\n");
	for(unsigned i=0;i<5;i++)
	{
		print_point(*ppoints[i]);
	}

	for(unsigned i=0;i<5;i++)
	{
		for(unsigned j=i;j<5;j++)
		{
			if(ppoints[i]->x > ppoints[j]->x)
			{
				point_t * tmp = ppoints[i];
				ppoints[i] = ppoints[j];
				ppoints[j] = tmp;	
			}


		}
	}

	printf("After sorting\n");
	for(unsigned i=0;i<5;i++)
	{
		print_point(*ppoints[i]);
	}

	point_t  result;
	add_points(ppoints[2],ppoints[3],&result);
	print_point(result);

	return EXIT_SUCCESS;
}
