//
//  fruit.hpp
//  template
//
//  Created by jiayou on 2021/10/21.
//

#ifndef fruit_hpp
#define fruit_hpp

#include <stdio.h>
#include <iostream>

template <typename T>
class Fruit {
public:
    Fruit();
};

template <typename T>
Fruit<T>::Fruit() {
    std::cout << "fruit template type :" << typeid(T).name() << std::endl;
}

class Apple1 : Fruit<int> {
public:
    Apple1();
};

Apple1::Apple1() {
    std::cout << "Apple1 is no template" << std::endl;
}

template <typename T>
class Apple2 : Fruit<int> {
public:
    Apple2();
};

template <typename T>
Apple2<T>::Apple2() {
    std::cout << "Apple2 template type :" << typeid(T).name() << std::endl;
}


void test7() {
    Apple1 a1;
    Apple2<double> a2;
}

template <typename T>
class Apple3 : Fruit<T> {
public:
    Apple3();
};

template <typename T>
Apple3<T>::Apple3() {
    std::cout << "Apple3 template type :" << typeid(T).name() << std::endl;
}

void test8() {
    Apple3<long> a3;
}




#endif /* fruit_hpp */
