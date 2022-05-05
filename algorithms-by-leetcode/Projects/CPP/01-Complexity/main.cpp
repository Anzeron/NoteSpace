//
//  main.cpp
//  01-Complexity
//
//  Created by Anzeron on 2021/11/9.
//

#include <iostream>
#include "complexity.hpp"


class Person {
    
public:
    Person() {
        std::cout << "init";
    }
};

class Person2 {
    
public:
    static Person p1;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << sum(3) << std::endl;
    Person2::p1;
    return 0;
}
