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

int main()
{
	unsigned a=53;
	unsigned b;

	b=a=34;

	printf("%u %u\n",a++,++b);
	printf("%u\n",b);

	a = f1()+f2()+f3();
	a = (a++) + ++a - --a + ++a;


	return 0;
}



