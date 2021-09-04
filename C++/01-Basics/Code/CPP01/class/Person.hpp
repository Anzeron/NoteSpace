//
//  Person.hpp
//  class
//
//  Created by jiayou on 2021/9/1.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>

class Person {
    
public:
    Person();
    Person(int age);
    Person(int age, int height);

    ~Person();
    
    void eat();
    void eat2();

private:
//    Person(Person& p);
    int age;
    int height;
};

#endif /* Person_hpp */
