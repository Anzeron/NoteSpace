### const限定符

`const`用来定义常量，默认该常量不会分配内存空间，编译器把常量名替换成对应的值，跟`#define`一样。

如果取常量地址或者使用`extern`定义常量，则会为该常量分配内存空间。

其格式如下：

```c++
const type name = value
```

#### 内部链接

`const`默认是内部链接；使用`extern`定义常量，则变成外部链接。

`Person.cpp`定义常量：

```c++
const int age = 12;
```

在其他地方，比如`main.cpp`使用该常量

```c++
extern const int age;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "person age is " << age << std::endl;
    return 0;
}
```

则链接的时候会报错:

```
Undefined symbol: _age
```

如果在`Person.cpp`，使用`extern`定义常量，则不会报错。

```c++
extern const int age = 12;
```



#### 跟`define`的区别

- 类型检测
  - `const` 有类型，可进行编译器类型安全检查
    - 比如，重载函数的参数类型，可以区分`int`，`short`
  - `define` 无类型，只是进行内容替换，不进行类型检查
- 作用域范围不同
  - `const` 的作用域是方法内或者文件内
  - `define`的作用域是从定义处到文件结尾

```c++
void testConstDefineType()
{
    #define kAge1 12
    const short kAge2 = 5;
    
    setAge(kAge1);  // int age
    setAge(kAge2);  // short age
}

void setAge(int age)
{
    std::cout << "set age int:" << age << std::endl;
}

void setAge(short age)
{
    std::cout << "set age short:" << age << std::endl;
}

void defineAge()
{
    // kAge1，#define从定义的地方
    std::cout << "set age long:" << kAge1 << std::endl;
}

```



### 引用

引用是已定义变量的别名，格式如下

```c++
Type &ref = var
```

- `&`在此不是求地址运算，而是起标识作用
-  类型标识符是指目标变量的类型
- 必须在声明引用变量时进行初始化
-  引用初始化之后不能改
- 不能有 `NULL` 引用。必须确保引用是和一块合法的存储单元关联
- 可以建立对数组的引用

#### 使用场景

使用场景:

- 函数参数
- 函数返回值
  - 不能返回局部变量的引用
    - 引用指向的是局部变量的内存,内存随时可能被回收，数据会发生变化
  - 函数当左值，必须返回引用

```c++
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

int & getAge1() {
    int a = 67; //局部变量
    
    return a;
}

int & getAge2() {
    static int a = 10; //静态变量，会一直存在
    
    return a;
}
```



#### 引用的本质：指针常量

引用的本质在 `C++`内部实现是一个指针常量，编译器在编译过程中使用常指针作为引用的内部实现。

- 引用所占用的空间大小与指针相同

```c++
Type& ref = val; // Type* const ref = &val;
```

示例

```c++
    int a = 10;
    int& aRef = a; //自动转换为 int* const aRef = &a;这也能说明引用为什么必须初始化
    aRef = 20; //内部发现 aRef 是引用，自动帮我们转换为: *aRef = 20
    cout << "a:" << a << endl;
    cout << "aRef:" << aRef << endl;
```



#### 指针引用

指针也是一种类型，也可以有引用，格式如下：

```c++
Type* pointer = new Type ;
Type*& aRef = point
```



#### 常量引用

格式

```c++
const Type& ref = val;
```

常量引用

- 不能修改`const `引用
- 字面量不能赋给引用，但是可以赋给` const `引用

常量引用主要用在函数的形参

- 由于引用可能导致实参随形参改变而改变，将其定义为常量引用可以消除这种副作用



示例

```c++
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
```

