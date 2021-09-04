//
//  main.cpp
//  class
//
//  Created by jiayou on 2021/9/1.
//

#include <iostream>

#include "Person.hpp"
#include "Person2.hpp"

void test1();
void test2();
void test3();
void line();
void printPerson2(Person2 p);
Person2 getPerson2();

int main(int argc, const char * argv[]) {
//    test1();
//    test2();
    test3();
    
    return 0;
}

// 调用普通构造函数
void test1()
{
    // 括号法
    Person p1;  // 无参构造函数
    //Person p2(); 会被当作一个函数定义  Empty parentheses interpreted as a function declaration
    Person p3(3);
    
    line();
    
    // 显示调用
    Person p4 = Person();
    Person p5 = Person(5);
    
    line();
    
    // 隐式转换
    Person p6 = 6; // Person p4 = Person(6);
    Person p7 = {7,7};  // Person p7 = Person(7,7);     C++ 11支持，列表初始化(List-initialization)
    
    line();
}

void test2()
{
    // 使用一个已经创建完毕的对象来初始化一个新对象
    Person2 p1;
    Person2 p2(p1);
    Person2 p3 = p1;
    
    line();
    
    // 值传递的方式给函数参数传值
    printPerson2(p1);
    
    // 以值方式返回局部对象
//    Person2 p = getPerson2();  No matching constructor for initialization of 'Person2'
}

void test3()
{
    Person *p = nullptr;
    p->eat();   //空指针，可以调用成员函数
    p->eat2();  //空指针，使用this，需要判断空指针
}

void printPerson2(Person2 p)
{
    
}

Person2 getPerson2()
{
    Person2 p;
    return p;
}


void line()
{
    std::cout << "------------------------" << std::endl;
}
