//
//  main.cpp
//  extern-c
//
//  Created by jiayou on 2021/8/31.
//

#include <iostream>
//extern void show();       Undefined symbol: show()


extern "C" void show();
extern "C" {
//    void show();
//    #include "Person.h"
}


int main(int argc, const char * argv[]) {
    show();
    return 0;
}
