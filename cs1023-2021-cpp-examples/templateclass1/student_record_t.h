#ifndef __MYPAIR_H
#define __MYPAIR_H

#include <string>

class student_record_t
{
    std::string name;
    unsigned height;

    public:
    student_record_t()=default;
    student_record_t(const std::string&,const unsigned& );
    std::string getname();
    unsigned getheight();
};


#endif