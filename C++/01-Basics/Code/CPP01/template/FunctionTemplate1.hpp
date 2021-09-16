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

int add1(int a, int b);

template <typename  T>
T add2(T a, T b);


template <typename  T>
T add2(T a, T b, T c);

template <typename  T>
T add2(T a, T b, double c);




#endif /* FunctionTemplate1_hpp */
