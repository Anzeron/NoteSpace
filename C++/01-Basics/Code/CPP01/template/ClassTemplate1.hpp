//
//  ClassTemplate1.hpp
//  template
//
//  Created by jiayou on 2021/9/28.
//

#ifndef ClassTemplate1_hpp
#define ClassTemplate1_hpp

#include <iostream>

template <typename T3> int size3(T3 &);

template <typename T>
class Stack {
private:
    T items[10];
    int top;
    
public:
    Stack();
    void setTop(int top);
    bool isEmpty();
    
    friend int size1(Stack<T> & stack);
    friend int size2(Stack<T> & stack);
    friend int size3<Stack<T>>(Stack<T> & stack);
    template <typename T4> friend int size4(T4 & stack);
};

template <typename T>
Stack<T>::Stack() {
    top = 0;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top == 0;
}

template <typename T>
void Stack<T>::setTop(int top) {
    this->top = top;
}

template <typename T>
int size1(Stack<T> & stack) {
    return stack.top;
}

int size2(Stack<int> & stack) {
    return stack.top;
}

// friend int size3<Stack<T>>(Stack<T> & stack);
// 用一个类型声明具体化，这个类型是Stack<T>
// 如果是其他类型，stack.top这一句会报错
template <typename T3>
int size3(T3 & stack) {
    return stack.top;
}

template <typename T4>
int size4(T4 & stack) {
    return stack.top;
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

void test9() {
    Stack<int> a;
//    int b = 1;
//    int length1 = size1(b); // 编译不过 Undefined symbol: size1(Stack<int>&)
    
    a.setTop(2);
    int length2 = size2(a);
    std::cout << "Stack<int> a length2: " << length2 << std::endl;
    
    a.setTop(3);
    int length3 = size3(a);
    std::cout << "Stack<int> a length3: " << length3 << std::endl;
    
    a.setTop(4);
    int length4 = size4(a);
    std::cout << "Stack<int> a length4: " << length4 << std::endl;
}

#endif /* ClassTemplate1_hpp */
