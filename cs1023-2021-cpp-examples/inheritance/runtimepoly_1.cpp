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
#include <iostream>
#include <cmath>
#include <fmt/core.h>

class shape //abstract class
{
    public:
         virtual std::string to_string() { 
                return fmt::format("This is a shape");
         }
         virtual double getarea() = 0;
};


class rectangle : public shape
{
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;

    public : 
          rectangle(double _x1, double _y1,double _x2, double _y2,
            double _x3, double _y3): x1(_x1),y1(_y1),x2(_x2),y2(_y2),
            x3(_x3),y3(_y3){}
        double getarea() override
        {
            double area = x1 *(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
            return area>0?area:-area;

        }
        void print_coordinates()
        {
            fmt::print("{} : {} \n {} : {} \n {} : {}",x1,y1,x2,y2,x3,y3);
        }

        std::string to_string()  
        {
            return fmt::format("This is a Rectangle");
        }

    

};


class circle : public shape{
    double x;
    double y;
    double r;
    public:
    circle(double _x, double _y, double _r): x(_x),y(_y),r(_r){}
    double getarea() override{
        double area= M_PI * r * r;
        return area;
    }
    std::string to_string() {
        return fmt::format("This is a circle");
    }
};

int main()
{

    unsigned choice;
    std::cout << "Enter 1 for rectangle 2 for circle" << std::endl;
    std::cin >> choice ;
    shape * s;
    switch(choice)
    {
        case 1 : s = new rectangle(1,2,3,4,5,6); break;
        case 2 : s = new circle (1,2,3);
    };
    fmt::print("{}\n",s->to_string());
    shape * s1 = new rectangle(1.1,2.1,5.1,8.1,3.3,10.2);
    shape * s2 = new circle (5.4,-8.2,4.5); 

    rectangle* r1=new rectangle(3.3,5.4,6.5,-9.8,10.2,-17.8);
 
    fmt::print("Area of rectangle is : {}\n",s1->getarea());
    fmt::print("Area of circle is {}\n",s2->getarea());
    fmt::print("{}\n",s1->to_string());
    r1->print_coordinates();

 return 0;
}
/// person
// villager : person
// soldier : person

// person {health,firepower,}
// perform_action()