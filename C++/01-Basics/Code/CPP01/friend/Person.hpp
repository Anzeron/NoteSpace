//
//  Person.hpp
//  friend
//
//  Created by jiayou on 2021/9/5.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>

class Person {
public:
    Person(int age);
    
    friend std::ostream & operator <<(std::ostream &os,const Person &p);
    
    
private:
    int age;
};

#endif /* Person_hpp */
