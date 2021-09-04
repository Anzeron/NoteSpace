//
//  Person.cpp
//  class
//
//  Created by jiayou on 2021/9/1.
//

#include "Person.hpp"
#include <iostream>

Person::Person()
{
    std::cout << "person alloc default" << std::endl;
}

Person::Person(int age)
{
    this->age = age;
    std::cout << "person alloc with age:" << age << std::endl;
}

Person::Person(int age, int height)
{
    this->age = age;
    this->height = height;
    std::cout << "person alloc with age:" << age << " height :" << height << std::endl;
}

//Person::Person(Person& p) {
//    this->age = p.age;
//    this->height = p.height;
//    std::cout << "person copy with age:" << age << std::endl;
//}

Person::~Person()
{
    std::cout << "person dealloc" << std::endl;
}

void Person::eat()
{
    std::cout << "person eat" << std::endl;
}

void Person::eat2()
{
    // 有了这个判断，对象空指针调用该函数，才能正常运行
    if (this == nullptr) {
        return;
    }
    std::cout << "person eat2 age" << this->age << std::endl;
}
