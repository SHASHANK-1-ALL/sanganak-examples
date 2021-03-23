
#include <iostream>
#include <string>


class entityt/*    Copyright (C) 2021  Saurabh Joshi

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
{
    private:
    std::string name;
    //accessible to descedents
    protected: 

    unsigned weight;
    unsigned volume;
    unsigned temperature;

    public:
    entityt(const std::string& _name, unsigned _weight, unsigned _volume,
                  unsigned _temperature):name(_name),weight(_weight),volume(_volume),
                  temperature(_temperature){}
    
    friend std::ostream& operator<<(std::ostream& out,const entityt& e);
    

    const std::string& getname() {return name;}
    unsigned getweight() {return weight;}
    unsigned getvolume() {return volume;}
    unsigned gettemperature() {return temperature;}
};



//operator overloading
std::ostream& operator<<(std::ostream& out, const entityt& e)
{
    out << "(" << e.name <<","<<e.weight <<"," << e.volume ;
    out << "," << e.temperature << ")";
    return out;
}

enum class reproduction_t {  mitosis, meiosis };

// entityt is called the base class
// livingt is called the derived class

// public derivation -> base class access qualifiers do not change
// protected derivation -> public of base class becomes protected
// private derivation -> everything of base class becomes private
class livingt : public entityt 
{
    protected:
    unsigned age;
    unsigned energy;
    bool ismulticellular;
    reproduction_t reproduction_type;

    public:
    unsigned getage() {return age;}

    


};



int main()
{
    entityt e("Alice",34,35,36);
    
    std::cout << "Entity is: " << e << std::endl;
    return 0;
}