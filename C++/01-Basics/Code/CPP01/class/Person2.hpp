//
//  Person2.hpp
//  class
//
//  Created by jiayou on 2021/9/2.
//

#ifndef Person2_hpp
#define Person2_hpp

#include <stdio.h>

class Person2 {
    
public:
    Person2();
    Person2(int age);
    
    Person2(Person2& p);


private:
    int age;
};

#endif /* Person2_hpp */
