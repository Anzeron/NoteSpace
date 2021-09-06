### 构造函数和析构函数

**构造函数语法：**`类名(){}`

- 构造函数，没有返回值也不写`void`

- 函数名称与类名相同

- 构造函数可以有参数，因此可以发生重载

- 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次

**析构函数语法：** `~类名(){}`

- 析构函数，没有返回值也不写`void`

- 函数名称与类名相同,在名称前加上符号  ~

- 析构函数不可以有参数，因此不可以发生重载

- 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次



**构造函数**的分类：

- 普通构造函数
- 复制构造函数



#### 使用普通构造函数

分类

- 无参构造函数，即默认构造函数
- 有参构造函数

调用方式：

- 括号法
- 显示法
- 隐式转换法

示例

```c++
Person::Person()
{
    std::cout << "person alloc default" << std::endl;
}

Person::Person(int age)
{
    this->age = age;
    std::cout << "person alloc with age:" << age << std::endl;
}

Person::Person(int age, int height)
{
    this->age = age;
    this->height = height;
    std::cout << "person alloc with age:" << age << " height :" << height << std::endl;
}

Person::~Person()
{
    std::cout << "person dealloc" << std::endl;
}
```

```c++
void test1()
{
    // 括号法
    Person p1;  // 无参构造函数，即默认构造函数
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
```



#### 默认构造函数

默认构造函数是没有参数的构造函数。类可以没有默认构造函数，但是调用相关代码则会报错，比如:

```c++
Person p1;  // 无参构造函数，即默认构造函数
```

使用如下方式获取默认构造函数：

- 没有自定义任何构造函数，则编译器会提供默认构造函数
- 自定义默认构造函数，以下2种方式，不能同时采用
  - 自定义没有参数的构造函数
  - 自定义有参数的构造函数，每个参数都有默认值



#### 使用拷贝构造函数

拷贝构造函数用于对象初始化，它将一个对象复制到新创建的对象。其函数原型如下：

```c++
class_name(const class_name&)
```

拷贝构造函数调用时机：

* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象，`Xcode 12.5.1`不支持，报错

示例

```c++
Person2::Person2()
{
    std::cout << "Person2 alloc default" << std::endl;
}

Person2::Person2(int age)
{
    this->age = age;
    std::cout << "Person2 alloc with age:" << age << std::endl;
}

Person2::Person2(Person2& p) {
    this->age = p.age;
    std::cout << "Person2 copy with age:" << age << std::endl;
}
```

```c++
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
```



#### 编译器自动生成构造和析构函数

默认情况下，编译器至少提供3个函数

1．默认构造函数(无参，函数体为空)

2．默认析构函数(无参，函数体为空)

3．默认拷贝构造函数，对属性进行值拷贝

如果有自定义构造函数：

* 自定义无参或者有参构造函数，编译器不在提供默认无参构造函数，提供默认拷贝构造函数


* 自定义拷贝构造函数，编译器再提供其他构造函数



### `this`指针和对象空指针

对象空指针也是可以调用成员函数的。但不建议这样做。

- 如果成员函数没有用到`this`指针，可以正常运行
- 如果用到`this`指针，需要判空，保证代码正常运行。

示例

```c++
void Person::eat()
{
    std::cout << "person eat" << std::endl;
}

void Person::eat2()
{
    // 有了这个判断，对象空指针调用该函数，才能正常运行
    if (this == nullptr) {
        return;
    }
    std::cout << "person eat2 age" << this->age << std::endl;
}
```

```c++
void test3()
{
    Person *p = nullptr;
    p->eat();   //空指针，可以调用成员函数
    p->eat2();  //空指针，使用this，需要判断空指针
}
```



### 运算符重载

运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

#### 赋值运算符重载

默认情况下，编译器提供上文中的构造函数和析构函数，还会提供赋值运算符`operator=`

示例

```c++
OPPerson::OPPerson(int age)
{
    this->age = age;
}

OPPerson & OPPerson::operator=(OPPerson &p)
{
    std::cout << "person operator=" << std::endl;
    this->age = p.age;
    return *this;
}

std::ostream & operator <<(std::ostream &os,const OPPerson &p)
{
    os << "Person with age:" << p.age <<std::endl;
    
    return os;
}
```

```c++
void test1()
{
    OPPerson p1 = OPPerson(1);      // 有参构造函数
    OPPerson p2 = OPPerson(2);      // 有参构造函数
    OPPerson p = p1;       // 编译器生成的拷贝构造函数
    std::cout << p;
    p = p2;     // 赋值运算符
    std::cout << p;
}
```

