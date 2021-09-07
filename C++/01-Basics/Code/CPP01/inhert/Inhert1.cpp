//
//  Inhert1.cpp
//  inhert
//
//  Created by jiayou on 2021/9/7.
//

#include "Inhert1.hpp"
#include <iostream>

using namespace std;


class Base
{
public:
    Base()
    {
        cout << "Base构造函数!" << endl;
    }
    
    Base(int age)
    {
        cout << "Base age 构造函数!" << endl;
    }
    
    ~Base()
    {
        cout << "Base析构函数!" << endl;
    }
};

class Son : public Base
{
public:
    Son()       // 调用Base的默认构造函数
    {
        cout << "Son构造函数!" << endl;
    }
    Son(int age):Base(age)       // 调用Base(int age)构造函数
    {
        cout << "Son age 构造函数!" << endl;
    }
    ~Son()
    {
        cout << "Son析构函数!" << endl;
    }
};


void test01()
{
    //继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
    Son s1;
    Son s2=Son(3);
}


