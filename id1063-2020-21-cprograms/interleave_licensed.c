/*    Copyright (C) 2021  Saurabh Joshi

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


void elem_copy(char* out,char* in, size_t elem_size)
{
	for(unsigned i=0;i<elem_size;i++)
	{
		(*out)=(*in);
		out++;
		in++;

	}
}

void interleave(void* out, void* in1, void* in2, size_t sz1, size_t sz2,size_t elem_size)
{
	char* p1 =(char*)in1;
	char* p2=(char *)in2;
	char* o = (char*) out;

	
	size_t min=sz1>sz2?sz2:sz1;
	size_t max=sz1<sz2?sz2:sz1;

	for(unsigned i=0;i<min;i++)
	{
		unsigned offset=i*elem_size;
		elem_copy(o,p1,elem_size);
		o+=elem_size;
		p1+=elem_size;
		elem_copy(o,p2,elem_size);
		o+=elem_size;
		p2+=elem_size;

	}

	if(min<max)
	{

		if(sz2>sz1)
		{
			p1=(char*)p2;
		}


		for(unsigned i=min;i<max;i++)
		{
			unsigned offset=i*elem_size;
			elem_copy(o,p1,elem_size);
			o+=elem_size;
			p1+=elem_size;

		}

	}

	

}





typedef struct
{
	char name[15];
	unsigned height;
} sr_t;

void print_record(const sr_t* sr)
{
	printf("%s : %u\n",sr->name,sr->height);
}

int main()
{


	sr_t sr1[]={{"alice",80},{"bob",90},{"charlie",100},{"derrick",110}};
	sr_t sr2[]={{"magan",85},{"chhagan",95},{"jagan",105}};


	sr_t out[7];

	interleave((void*)out,(void*)sr2,(void*)sr1,3,4,sizeof(sr1[0]));

	for(unsigned i=0;i<7;i++)
	{
		print_record(&out[i]);
	}

}
