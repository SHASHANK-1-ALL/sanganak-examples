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

/*
 * Inputs : a, b
 *
 * Output : mysum, myprod
 *
 */
void myadd(const int* a, const int* b, int* mysum, int* myprod)
{
#ifdef DEBUG
	printf("Inside myadd");
	printf("%p : %p : %p : %p\n",mysum,myprod,&mysum,&myprod);
#endif
	(*mysum)= (*a)+(*b);
	(*myprod) = (*a) * (*b);
	
}

int main()
{
	int a=5;
	int b=7;
	int sum;
	int tmp[10];
	int prod;
	printf("%d: %d : %p : %p \n",sum,prod,&sum,&prod);
	myadd(&a,&b,&sum,&prod);
	printf("%d : %d : %d : %d\n",a,b,sum,prod);
	return 0;
}
