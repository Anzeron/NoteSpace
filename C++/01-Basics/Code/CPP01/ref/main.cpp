//
//  main.cpp
//  ref
//
//  Created by jiayou on 2021/8/26.
//

#include <iostream>
using namespace std;

void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();

void refSwap(int & m,int & n);
int & getAge1();
int & getAge2();

struct Teacher{
    int mAge;
 };

void pointByReference(Teacher*& teacher);

int main(int argc, const char * argv[]) {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
    test07();
    
    return 0;
}

void test01()
{
    //给变量a 取一个别名b，b必须先初始化
    int a = 10;
    int& b = a;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "------------" << endl;
}

void test02()
{
    //1. 建立数组引用方法一
    typedef int ArrRef[10];
    int arr[10];
    ArrRef& aRef = arr;
    for (int i = 0; i < 10;i ++){
        aRef[i] = i+1;
    }
    for (int i = 0; i < 10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
        
    //2. 建立数组引用方法二
    int(&f)[10] = arr;
    for (int i = 0; i < 10; i++){
        f[i] = i+10;
    }
    for (int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test03()
{
    int a = 10;
    int b = 5;
    refSwap(a, b);
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "------------" << endl;
}

void test04()
{
    int & a1 = getAge1();   // 引用指向的是局部变量的内存,内存随时可能被回收，数据会发生变化
    int & b1 = getAge2();
    cout << "a1是随机值:" << a1 << endl;    // 随机值
    cout << "b1:" << b1 << endl;
    cout << "------------" << endl;
    
    int a2 = getAge1();     // 会做一次值拷贝，数据没什么问题，但不建议这样用
    int b2 = getAge2();
    cout << "a2: " << a2 << endl;
    cout << "b2:" << b2 << endl;
    cout << "------------" << endl;
    
    // 函数作为左值
    getAge2() = 14;
    int b3 = getAge2(); // b3是14
    cout << "函数作为左值之后，b3:" << b3 << endl;
}

void test05()
{
    int a = 10;
    int& aRef = a; //自动转换为 int* const aRef = &a;这也能说明引用为什么必须初始化
    aRef = 20; //内部发现 aRef 是引用，自动帮我们转换为: *aRef = 20
    cout << "a:" << a << endl;
    cout << "aRef:" << aRef << endl;
}

void test06()
{
    Teacher *t = new Teacher;
    pointByReference(t);
    cout << "AllocateAndInitByReference:" << t->mAge << endl;
    delete t;
}

void test07()
{
//    int &ref = 1; 编译不过
    const int &ref1 = 100;
    int age = 10;
    const int &ref2 = age;
    cout << "init var age:" << age << endl;
    cout << "const ref age:" << ref2 << endl;
//    ref2 = 5; 编译不过
    age = 5;
    
    cout << "change var age:" << age << endl;
    cout << "const ref age:" << ref2 << endl;
}


void refSwap(int & m,int & n)
{
    int temp = m;
    m = n;
    n = temp;
}

int & getAge1() {
    int a = 67; //局部变量
    
    return a;
}

int & getAge2() {
    static int a = 10; //静态变量，会一直存在
    
    return a;
}


void pointByReference(Teacher*& teacher)
{
    teacher->mAge = 5;
}
 
