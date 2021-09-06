//
//  main.cpp
//  operator
//
//  Created by jiayou on 2021/9/6.
//

#include <iostream>
#include "OPPerson.hpp"

void test1();

int main(int argc, const char * argv[]) {
    test1();
    
    return 0;
}

void test1()
{
    OPPerson p1 = OPPerson(1);      // 有参构造函数
    OPPerson p2 = OPPerson(2);      // 有参构造函数
    OPPerson p = p1;       // 编译器生成的拷贝构造函数
    std::cout << p;
    p = p2;     // 赋值运算符
    std::cout << p;
}


