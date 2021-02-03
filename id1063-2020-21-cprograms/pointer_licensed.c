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
