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


#include <string.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct 
{
	char name[15];
	unsigned height;
	unsigned weight;

} sr_t;

//typedef struct student_record_t sr_t;

void swap(void** e1, void** e2)
{
	void* tmp = *e1;
	*e1=*e2;
	*e2=tmp;
}




void sort(void** arr,size_t arr_size, int (*compare)(void**,void**))
{

	sr_t sr_arr[]={{"alice",180,80},{"Bob",170,90},{"Charlie",155,60},{"Derick",140,75},{"Elon",160,70}};
//	
			printf("Pointer diff: %ld\n",(*(double**)arr)-(double *)(&sr_arr[2]));
	char** endp=(char**)arr+(arr_size-1);
	char** endp1=(char**)endp+1;
	for(char **p=(char**)arr;p!=endp;p++)
	{
		for(char**p1=(char**)p;p1!=endp1;p1++)
		{
			printf("Pointer diff: %ld\n",(*(double**)p1)-(*(double**)p));
			if(compare((void**)p,(void**)p1)>0)
			{
				swap((void**)p,(void**)p1);

			}

		}
	}
	
}

int srt_height_compare(void** sr1, void** sr2)
{
	unsigned h1= (*(sr_t**)(sr1))->height;
	unsigned h2= (*(sr_t**)(sr2))->height;
	if(h1<h2) return -1;
	if (h1>h2) return 1;
	return 0;
	
}
int srt_weight_compare(void** sr1, void** sr2)
{
	unsigned h1= (*(sr_t**)(sr1))->weight;
	unsigned h2= (*(sr_t**)(sr2))->weight;
	if(h1<h2) return -1;
	if (h1>h2) return 1;
	return 0;
	
}


int double_compare(void** d1, void** d2)
{
	double t1=(**(double**)d1);
	double t2=(**(double**)d2);
     return t1<t2?-1:((t1>t2)?1:0);
}

int srt_namelength_compare(void** sr1,void**sr2)
{
  unsigned l1=strlen((*(sr_t**)sr1)->name);
  unsigned l2=strlen((*(sr_t**)sr2)->name);
	if(l1<l2) return -1;
	if(l1>l2) return 1;
	return 0;
}

void print_student_record(const sr_t* sr)
{
	printf("Name: %s , height: %u, weight: %u\n",sr->name,sr->height,sr->weight);
}

int main()
{
	sr_t arr[]={{"alice",180,80},{"Bob",170,90},{"Charlie",155,60},{"Derick",140,75},{"Elon",160,70}};


	size_t arr_size=sizeof(arr)/sizeof(sr_t);
	sr_t* ptr_arr[arr_size];

	for(unsigned i=0;i<arr_size;i++)
	{
		ptr_arr[i]=&arr[i];
	}

#if 0
	double darr[]= {1.1,1.2,-90.89,-230.12,0};
	double* ptr_darr[5];
	for(unsigned i=0;i<5;i++)
	{
		ptr_darr[i]=&darr[i];
	}
#endif
	sort((void**)ptr_arr,arr_size,srt_weight_compare);
//	sort((void**)ptr_darr,5,double_compare);

#if 0
	for(unsigned i=0;i<5;i++)
	{
		printf("%lf\n",*ptr_darr[i]);
	}
#endif

	for(unsigned i=0;i<arr_size;i++)
	{
		print_student_record(ptr_arr[i]);

	}

	return EXIT_SUCCESS;
}

