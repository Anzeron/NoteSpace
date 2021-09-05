//
//  Person.cpp
//  friend
//
//  Created by jiayou on 2021/9/5.
//

#include "Person.hpp"

Person::Person(int age)
{
    this->age = age;
}

std::ostream & operator <<(std::ostream &os,const Person &p)
{
    os << "Person with age:" << p.age <<std::endl;
    
    return os;
}

