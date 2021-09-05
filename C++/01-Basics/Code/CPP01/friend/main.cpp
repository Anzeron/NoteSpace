//
//  main.cpp
//  friend
//
//  Created by jiayou on 2021/9/5.
//

#include <iostream>
#include "Person.hpp"

void test();

int main(int argc, const char * argv[]) {
    test();
    return 0;
}

void test()
{
    Person p = Person(3);
    std::cout << p;
}
