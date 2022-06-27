### runtime

#### macOS Monterey系统成功编译objc4-838

https://juejin.cn/post/7068539803318353928

#### [深入理解 OC/C++ 闭包](https://mp.weixin.qq.com/s/NEvtm_yBMghyP_WTUATy8g)

ObjC 编译器允许用户在同一个源文件里自由地混合使用 C++ 和 ObjC，相对于其它语言与 C++ 的文件隔离和架桥通信（Kotlin 使用 JNI，Dart 使用 FFI），Objective-C++ 的同文件混编方式无疑是令人舒畅的。虽然 Objective-C++ 没有为 ObjC 和 C++ 类增加功能，类的体系结构也互相独立，类之间不能互相继承，但有时二者也会相互把自己的魔杖伸向对方领域，从而会引发一些比较费解的问题。本文就从两种语言闭包混合捕获的原理出发，了解其混编方式背后机制的冰山一角，也帮助大家写出更好的 ObjC/C++ 混编代码。

#### [libffi的调用流程](https://www.jianshu.com/p/4644b1584a1f)

FFI (Foreign Function Interface) 是用来与其它语言交互的接口，是实现跨语言调用的主要方式之一。其通过直接将其它语言的接口内嵌实现更高的执行效率，而通过进程间通信 (IPC) 或网络通信 (RPC, RESTful 等) 则至少需要两个独立进程才能实现。

libffi 是 ffi 的主流实现方式，主要使用 C 和汇编实现，最常用作编译语言和解释语言实现之间的桥接技术。本文从 libffi 的调用流程出发，带大家了解 ffi_call 和 ffi_closure 是怎样帮助我们实现动态调用的。

### 内存管理

#### [探秘 AutoreleasePool 实现原理](https://mp.weixin.qq.com/s/fcS6aiddSjeQSfjMY-8Oow)

无论是 MRC 还是 ARC 时代，autorelease 最大的作用，是在大量创建对象的同时，通过修饰让内存得到提前释放，从而降低内存峰值。本文就旨在通过分析源码了解内部是如何实现的。

### TIPS

#### [iOS 15.4 12小时制 时间格式转换崩溃 - 掘金](https://juejin.cn/post/7077493937383948295)

本文介绍了一个在iOS15.4系统由于时间转换造成的崩溃

### 深入操作系统

#### [wakeup in XNU](http://djs66256.github.io/2021/04/03/2021-04-03-wakeup-in-XNU/)

关注性能的读者可能会碰到有一种有一种被系统 kill 类型是 weakup，又因为收集到的日志不足以定位问题，本文通过另一种思路去解决这个问题。整体介绍了weakup是什么、系统如何统计的以及关键的是如何治理。

- 为什么要统计 wakeup
- wakeup 是什么
- wakeup 如何统计的
- wakeup 治理
- 监控与防劣化
