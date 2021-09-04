//
//  Person2.cpp
//  class
//
//  Created by jiayou on 2021/9/2.
//

#include "Person2.hpp"

#include <iostream>

Person2::Person2()
{
    std::cout << "Person2 alloc default" << std::endl;
}

Person2::Person2(int age)
{
    this->age = age;
    std::cout << "Person2 alloc with age:" << age << std::endl;
}

Person2::Person2(Person2& p) {
    this->age = p.age;
    std::cout << "Person2 copy with age:" << age << std::endl;
}
