//
//  complexity.cpp
//  01-Complexity
//
//  Created by Anzeron on 2021/11/9.
//

#include "complexity.hpp"
#include <iostream>

int sum(int num) {
    int sum = 0;
    
    for (int i = 1; i <= num; i++) {
        sum += i;
    }
    
    return sum;
}

void test() {
    int a = 1;
    int b = 2;
    if (b > a) {
        std::cout << "b > a" << std::endl;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }
}

void test2(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i << std::endl;
    }
}

void test3(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << i * j << std::endl;
        }
    }
    
    int k =  0;
    while (k < n) {
        n = k * 2;
    }
    
    int *p = (int *)malloc(n * sizeof(int));
    
    free(p);
}

