//
//  OPPerson.cpp
//  operator
//
//  Created by jiayou on 2021/9/6.
//

#include "OPPerson.hpp"

OPPerson::OPPerson()
{
    this->age = 0;
}

OPPerson::OPPerson(int age)
{
    this->age = age;
}

OPPerson & OPPerson::operator=(OPPerson &p)
{
    std::cout << "person operator=" << std::endl;
    this->age = p.age;
    return *this;
}

std::ostream & operator <<(std::ostream &os,const OPPerson &p)
{
    os << "Person with age:" << p.age <<std::endl;
    
    return os;
}
