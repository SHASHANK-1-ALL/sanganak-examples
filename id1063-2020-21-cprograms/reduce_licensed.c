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

struct _student_record_t
{
	char name[10];
	unsigned height;
};

typedef struct _student_record_t student_record_t;
#if 0
void int_add(void* arg_1,void* arg_2)
{
   (*(int*)arg_1)= (*(int *)arg_1) + (*(int*)(arg_2));
}
void int_mul(void* arg_1,void* arg_2)
{
   (*(int*)arg_1)= (*(int *)arg_1) * (*(int*)(arg_2));
}
#endif
void reduce(void *arr, size_t arr_size, size_t elem_size,void (*fun)(void*,const void*),void* init_value)
{
	for(unsigned i=0;i<arr_size;i++)
	{
		void* p=(void*)(((char*) arr)+(i*elem_size));
		fun(init_value,p);
	}
}

/*
 * precondition: arg_1 and arg_2 points to student_record_t
 *
 *
 *
 */
void find_maxheight_student(void* arg_1, void* arg_2)
{
        student_record_t* p1=(student_record_t*) arg_1;
        student_record_t* p2=(student_record_t*) arg_2;

	if(p1->height < p2->height) *p1=*p2;
}

void find_longestname_student(void* arg_1, void* arg_2)
{
        student_record_t* p1=(student_record_t*) arg_1;
        student_record_t* p2=(student_record_t*) arg_2;

	if(strlen(p1->name)<strlen(p2->name)) *p1=*p2;
}

int main()
{
	
	student_record_t arr[]={{"alice",5},{"bobbobbo",10},{"charlie",15}};

	student_record_t* result=(student_record_t*)malloc(sizeof(student_record_t));
			result->height=0;
			result->name[0]='N';
			result->name[1]='\0';
			void (*fun)(void*, const void*);
			fun = (void (*)(void*,const void*))(result); 
		//	find_maxheight_student=result;
	reduce(arr,3,sizeof(student_record_t),fun,result);
	printf("%s : %u\n",result->name,result->height);
	return EXIT_SUCCESS;
}
