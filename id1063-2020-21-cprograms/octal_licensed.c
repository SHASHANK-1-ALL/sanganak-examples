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
#include <limits.h>

int  is_palindrome(unsigned num)
{
	unsigned l=1<<(________);
	unsigned r=1;

	for(;l>r;l>>=1,r<<=1)
	{
		if(_________) return 0;
	}
	return 1;
}

int main()
{
	for(unsigned i=0x000ff000;i!=UINT_MAX;i++)
	{
		if(is_palindrome(i))
		{
			printf("%u is a palindrome\n",i);
		}
	}

	return 0;
}
