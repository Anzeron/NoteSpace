//
//  main.cpp
//  const
//
//  Created by jiayou on 2021/8/25.
//

#include <iostream>
#include "Person.hpp"
//#include "Student.hpp"

extern const int age;

int main(int argc, const char * argv[]) {

    testConstDefineType();
    return 0;
}

void testConst1()
{
    std::cout << "person age is " << age << std::endl;
    std::cout << "person age2 is " << age2 << std::endl;
}
