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


#include "circle.h"
#include "shape.h"
#include "rectangle.h"
#include "shape_factory.h"
#include <fmt/core.h>

int main()
{
    shape_t *s1 = make_shape(shape_choicet::SHAPE); 
    shape_t* s2 = make_shape(shape_choicet::RECTANGLE);
    shape_t *s3 = make_shape(shape_choicet::CIRCLE);

    fmt::print("{} \n {} \n {}\n",s1->to_string(),s2->to_string(), s3->to_string());
    
    return 0;
}