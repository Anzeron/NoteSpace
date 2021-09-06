//
//  OPPerson.hpp
//  operator
//
//  Created by jiayou on 2021/9/6.
//

#ifndef OPPerson_hpp
#define OPPerson_hpp

#include <stdio.h>
#include <iostream>

class OPPerson {
    
public:
    OPPerson();
    OPPerson(int age);
    OPPerson& operator=(OPPerson &p);
    
    friend std::ostream & operator <<(std::ostream &os,const OPPerson &p);
    
    
private:
    int age;
};
  

#endif /* OPPerson_hpp */
