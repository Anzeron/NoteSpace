//
//  ClassTemplate1.hpp
//  template
//
//  Created by jiayou on 2021/9/28.
//

#ifndef ClassTemplate1_hpp
#define ClassTemplate1_hpp

#include <iostream>

template <typename T>
class Stack {
private:
    T items[10];
    int top;
    
public:
    Stack();
    bool isEmpty();
};

template <typename T>
Stack<T>::Stack() {
    top = 0;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top == 0;
}

template class Stack<std::string>;      // 显示实例化
void test6() {
    Stack<int> s1;      // 隐式实例化Stack<int>
    if (s1.isEmpty()) {
        std::cout << "Stack<int> s1 is empty: " << std::endl;
    }
    
    Stack<double> *s2;      // 没有实例化，因为没有生成对象
    s2 = new Stack<double>();   // 实例化Stack<double>
    delete s2;
}

#endif /* ClassTemplate1_hpp */
