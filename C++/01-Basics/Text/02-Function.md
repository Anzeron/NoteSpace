### extern C

对于` void show()`函数，如果在`C `实现，在`C++`里调用该函数

- `C `会编译成`show`符号
- `C++`会编译成`_Z6show`符号，具体名称取决于编译器

这会导致程序在链接阶段发生错误`Undefined symbol: show()`，原因是

- ` void show()`函数是用`C `实现，生成的符号是 `show`

- 但`C++`在链接阶段会去找`_Z6show`符号，找不到该符号



`extern "C"`的作用是： `C++`调用的 `C `代码，编译器按`C `的方式进行**编译**和**链接**。

这样可以避免找不到符号的问题。

示例，`C `文件：

```c
// Person.h
#ifndef Person_h
#define Person_h

#ifdef __cplusplus
extern "C" {
#endif // !__cplusplus

#include <stdio.h>

void show(void);

#ifdef __cplusplus
}
#endif //

#endif /* Person_h */

// Person.c
void show(void)
{
    printf("hello world \n");
}
```

在`C++`里调用该函数

```c++
//extern void show();       Undefined symbol: show()

extern "C" void show();		// 第一种写法
extern "C" {
//    void show();			// 第二种写法
//    #include "Person.h"			// 第三种写法
}

int main(int argc, const char * argv[]) {
    show();
    return 0;
}
```



