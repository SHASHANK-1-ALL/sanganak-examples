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
#include <string>
//#include <format>
#include <fmt/core.h>
class entityt{
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
    
   // std::ostream& operator<<(std::ostream& out,const entityt& e);
    

    const std::string& getname() const {return name;}
    unsigned getweight() const {return weight;}
    unsigned getvolume() const {return volume;}
    unsigned gettemperature() const {return temperature;}
};



//operator overloading
std::ostream& operator<<(std::ostream& out, const entityt& e)
{
    out << "(" << e.getname() <<","<<e.getweight() <<"," << e.getvolume() ;
    out << "," << e.gettemperature() << ")";
    return out;
}

enum class reproduction_t {  mitosis, meiosis };

// entityt is called the base class
// livingt is called the derived class

// public derivation -> base class access qualifiers do not change
// protected derivation -> public of base class becomes protected
// private derivation -> everything of base class becomes private
class livingt :  private entityt 
{
    protected:
    unsigned age;
    unsigned energy;
    bool ismulticellular;
    reproduction_t reproduction_type;

    public:
    livingt(const std::string& _name,unsigned _weight, unsigned _volume,
        unsigned _temperature,unsigned _age, unsigned _energy, bool _ismulticellular,
        reproduction_t _rtype):entityt(_name,_weight,_volume,_temperature),
        age(_age),energy(_energy),ismulticellular(_ismulticellular),
        reproduction_type(_rtype){}
    unsigned getage() const {return age;}
    unsigned getenergy() const {return energy;}
    bool ismulticelluar() const {return ismulticellular;}
    reproduction_t getrtype() const {return reproduction_type;}

    std::string getname() const { return "livingt:"+entityt::getname();}
    std::string to_string() const{
        return fmt::format("(livingt : name {}, weight {}, volume {}, temp {} \
                                age {}, energy {}, multicellular {}, \
                                reproduction type {}", getname() ,weight, volume,
                                temperature, age, energy, ismulticellular, reproduction_type);
    }

};



#if 0
namespace myutil{

template <typename T>
class pair_t
{
    T first;
    T second;
    public:
      pair_t(T f, T s):first(f),second(s){}
     // pair_t<T> operator+(pair_t<T> p); 
      T getfirst() const {return first;}
      T getsecond() const {return second;}
      std::string to_string() const ;

};

template <typename T>
pair_t<T> operator+(pair_t<T> p1, pair_t<T> p2) //m1+m2; m1.+(m2)
{
    return pair_t<T>(p1.getfirst()+p2.getfirst(),p1.getsecond()+p2.getsecond());

};
template <typename T>
std::string pair_t<T>::to_string() const
{
   return fmt::format("{} : {}",first,second);   
}
/*
template <typename T>
std::ostream& operator<<(std::ostream& out,const pair_t<T>& p)
{
  out << p.getfirst() << ":" << p.getsecond();
  return out;
}
*/

};

#endif
/*
template<typename T>
std::ostream& operator<<(std::ostream& out,const myutil::pair_t<T>& p)
{
    out << "This is another function" << p.getsecond() << ":" << p.getfirst();
    return out;
}
*/

int main()
{
    livingt l("Alice",400,200,100,100,300,true,reproduction_t::meiosis);
    entityt e("Bob",40,50,60);

    std::cout << l.getname() << std::endl;
    std::cout << e.getname() << std::endl;
   // ::operator<<(std::cout,(p+p1)) << std::endl;
   // entityt e("Alice",34,35,36);
    
    //std::cout << "Entity is: " << e << std::endl;
    return 0;
}