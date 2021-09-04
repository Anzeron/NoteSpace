//
//  Person.cpp
//  const
//
//  Created by jiayou on 2021/8/25.
//

#include "Person.hpp"
#include <iostream>

extern const int age = 12;

void setAge(int age);
void setAge(short age);

void printAge()
{
    std::cout << "person age is " << age2 << std::endl;
}

void testConstDefineType()
{
    #define kAge1 12
    const short kAge2 = 5;
    
    setAge(kAge1);  // int age
    setAge(kAge2);  // short age
}

void setAge(int age)
{
    std::cout << "set age int:" << age << std::endl;
}

void setAge(short age)
{
    std::cout << "set age short:" << age << std::endl;
}

void defineAge()
{
    // kAge1，#define从定义的地方
    std::cout << "set age long:" << kAge1 << std::endl;
}
