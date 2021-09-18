//
//  FunctionTemplate1.hpp
//  template
//
//  Created by jiayou on 2021/9/15.
//

#ifndef FunctionTemplate1_hpp
#define FunctionTemplate1_hpp

#include <stdio.h>
#include <iostream>

void test1();
void test2();
void test3();

int add1(int a, int b);

template <typename  T>
T add2(T a, T b);


template <typename  T>
T add2(T a, T b, T c);

template <typename  T>
T add2(T a, T b, double c);

class FTPerson {
public:
    int age;
};

template <typename  T>
bool equal(T &a, T &b);

template<> bool equal(FTPerson &p1, FTPerson &p2);




#endif /* FunctionTemplate1_hpp */
