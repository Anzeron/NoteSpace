//
//  FunctionTemplate1.cpp
//  template
//
//  Created by jiayou on 2021/9/15.
//

#include "FunctionTemplate1.hpp"



int add1(int a, int b)
{
    return a + b;
}

template <typename  T>
T add2(T a, T b)
{
    std::cout << "T add2(T a, T b)" << std::endl;
    return a + b;
}

template <typename  T>
T add2(T a, T b, T c)
{
    std::cout << "T add2(T a, T b, T c)" << std::endl;
    return a + b + c;
}

template <typename  T>
T add2(T a, T b, double c)
{
    std::cout << "T add2(T a, T b, double c)" << std::endl;
    return a + b + c;
}

template <typename  T>
bool equal(T &a, T &b) {
    std::cout << "equal(T &a, T &b)" << std::endl;
    return a == b;
}

template<> bool equal(FTPerson &p1, FTPerson &p2) {
    std::cout << "equal(FTPerson &p1, FTPerson &p2)" << std::endl;
    return p1.age == p2.age;
}

void test1()
{
    int a1 = 1;
    int b1 = 2;
    add2(a1, b1);

    int a2 = 1;
    short b2 = 1.0;
//     add2(a2, b2);  // No matching function for call to 'add2'
    add2<int>(a2, b2);      // short被隐式转换成int
}

void test2()
{
    int a1 = 1;
    int b1 = 2;
    double c1 = 1.3;
    add2(a1, b1, a1);
    add2(a1, b1, c1);
}

void test3()
{
    FTPerson p1;
    FTPerson p2;
    
    equal(p1, p2);
}



 
