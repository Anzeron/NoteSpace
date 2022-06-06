### 深入Swift

#### 深入Swift的基本概念

https://juejin.cn/column/7069654800002252808

- [Swift进阶(一) —— 类与结构体](https://juejin.cn/post/7048633193666183176)
- [Swift进阶(二) —— 方法探究](https://juejin.cn/post/7050873481029746696)
- [Swift进阶(三）—— 属性](https://juejin.cn/post/7062732599835721735)
- [Swift进阶(四）—— 指针](https://juejin.cn/post/7069654422359392292)
- [Swift进阶(五）—— 内存管理](https://juejin.cn/post/7071048325193007134)
- [Swift进阶(六）—— 枚举和可选类型](https://juejin.cn/post/7072287470791966750)



#### 使用类和协议，实现虚类

https://www.swiftbysundell.com/articles/abstract-types-and-methods/

方法定义在 Protocol 中（包含 associatedtype ），成员变量定义在 Class 中，再使用 typealias 将 Protocol 与 Class 组合成一个类型进行使用。

这个方案也会带来一些问题，但也有各自的解决方案，酌情选取即可。

- 由于新的类型也包含 associatedtype，因此[无法被直接当类型使用](https://www.swiftbysundell.com/questions/referencing-generic-protocols/)，可以使用[类型擦除](https://www.swiftbysundell.com/articles/different-flavors-of-type-erasure-in-swift/)解决。
- 无法基于新的类型添加 extension。只能在原本的 Class 中添加方法，但有时这个方法又不应该或者不能添加在原本的 Class中。这时则可以在 Protocol 中也重复声明 Class 中对应的变量，而把方法添加在 Protocol 对应的 extension 中。



#### [如何选择AnyObject, Any, and any](https://www.avanderlee.com/swift/anyobject-any/)

Swift 5.6 在 [SE-355](https://github.com/apple/swift-evolution/blob/main/proposals/0335-existential-any.md) 引入了 `any` 关键词，加上之前已有的 `AnyObject` 和 `Any`(注意是大写)。本文介绍了三个关键词各自的使用场景并着重介绍新引入的 `any` 的作用。



#### [Type placeholders in Swift](https://www.swiftbysundell.com/articles/type-placeholders-in-swift/)

Swift 5.6 中引入了 **Type Placeholders** 来进一步优化类型推断，允许使用 `_` 来让编译器自动推断类型，对于例如 `CurrentValueSubject<Output, Failure>` 这一类的复杂范型更加友好。



#### [Swift 中的 @objc、@objcMembers 关键字探讨](https://mp.weixin.qq.com/s/Yfk_hI3kIIOBzvmwc_6w_w) 

@东坡肘子：我们说 Objective-C 是一门动态语言，决策会尽可能地推迟到运行时。而 Swit 是一门静态语言，也就是说 Swift 的对象类型、调用的方法都是在编译期就确定的，这也是为什么 Swift 比 OC 性能高的原因。但是在 Swift 中所有继承自 NSObject 的类，仍然保留了 Objective-C 的动态性。如果想要使用它的动态性就需要加上 @objc 关键字，本篇文章就来讲一下，哪些情况需要用到 @objc。

1. Protocol如果是optional(非必须实现)的，必须加上@objc
2. 利用#selector调用的方法,被调用的方法须加上@objc
3. 使用kvc时
4. NSPredicate筛选
5. oc与swift混合开发，swift方法/属性需要被oc调用的，要加上@objc
6. swift的枚举需要被oc使用的



### 写更好的代码

#### [@available 与调用方进行沟通](https://mp.weixin.qq.com/s/e2_mWNx4HduM57LF0xTvqA) 

@东坡肘子：保持代码不变很难，因为需求不断在变化，系统、框架不断在更新。那么项目实践中，往往会废弃掉一些类或方法。如果是自己独立维护代码，且不需要将代码给他人使用，废弃 API 对你来说是非常简单的，直接改动源码即可。但是对于多人合作的项目，特别是开源的库，废弃一个公开的 API 不是简单地改动下代码就可以，因为你的改动将会影响使用你这个库的所有代码。公开的 API 的更新换代，就相当于你改动了和别人约定的契约一样，这也侧面反映了作者的专业水平。那么如果要废弃一个 API，在 Swift 中我们该如何做？



### 协议

#### 组合多个协议

https://www.swiftbysundell.com/articles/combining-protocols-in-swift/

几种不同的方法来组合多个协议的功能。编程并没有绝对的标准答案，不同方案都有各自的特点。协议默认实现、协议扩展、范型约束



#### [PROTOCOL & GENERIC IN SWIFT](http://nonomori.bitcron.com/post/protocolandgenericinswift/readme)

Swift 基于面向协议的设计提供了简明&丰富的抽象手段，这也给复杂场景使用 Protocol 带来不少歧义，官方最近几个版本与之相关的设计也持续被讨论并改进。比如 [Opaque Result Types](https://github.com/apple/swift-evolution/blob/master/proposals/0244-opaque-result-types.md)、[Unlock existentials for all protocols](https://github.com/apple/swift-evolution/blob/main/proposals/0309-unlock-existential-types-for-all-protocols.md)。

本文从一个简单例子对比范型及类型擦除如何应用及二者内部实现的不同，帮助大家加深理解：

- 静态 vs 动态
- 编译器生成模板代码 vs 通过 Existential Container 隐藏类型



### 内存管理

#### weak是如何实现的

https://mp.weixin.qq.com/s/_N98ADlfQCUkxYjmH0SvZw

#### WWDC21 Swift 中的 ARC 机制: 从基础到进阶

https://mp.weixin.qq.com/s/ZJ3gVI-jzDcKpRKa0IMi0A



#### [Weak self, a story about memory management and closure in Swift](https://benoitpasquier.com/weak-self-story-memory-management-closure-swift/)

在 Swift 里我们经常需要使用 weak 和 unowned 来解决循环引用的问题。

只使用一个闭包的时候，引用的逻辑关系很简单明了，但闭包嵌套的时候，即使使用了 weak 也有可能会不小心产生循环引用，这篇文章就针对这种情况进行了仔细的说明，并且提供对应的解决方案。



#### [理解 Swift 中的指针](https://mp.weixin.qq.com/s/4O5RZCiR9-kUOHJ5SdE9jg)

Swift中的指针分为两类

1. typed pointer： 指定数据类型指针，即 UnsafePointer<T>。
2. raw pointer： 未指定数据类型的指针（原生指针） ，即 UnsafeRawPointer。

每一类又分可变不可变，pointer（单个值） 与 bufferPointer（相同类型集合）。

文章通过示例代码，详细介绍了这些指针的使用方式。



### 异步

#### [Introducing Swift Async Algorithms](https://www.swift.org/blog/swift-async-algorithms/)

 async/await 操作符相信大家都不陌生，在很多语言中都对起进行了支持，比如 js。async/await 最大的意义在于让我们可以用顺序结构来书写异步代码，更加清晰，避免了callback hell。3月份，Swift 维护小组发布了原型版本的 Swift Async Algorithm Package，其中就包含了 async/await 的实现以及专门用来处理异步系列的算子，比如 Zip/CombineLast/Merge/Chain/Buffer/Debounce/Throttle。这些算子相信大家都不陌生，其实用法和在处理集合类型中使用是没有太大区别的，只是搭配 async/await 来使用就能够并发强大的能量，使用简洁的代码描述复杂的异步逻辑。感兴趣的同学可以持续关注这个 package 的后续进展。



### SwiftUI

#### [Jenga - 基于 Swift ResultBuilder 优雅的构建 UITableView](https://github.com/fanglinwei/Jenga)

[@老峰](https://github.com/gesantung)：Jenga 是一个基于 ResultBuilder 封装的类 SwiftUI 使用声明式语法构建 UITableView 开源库，提供了 State 和 Binding 特性，代码简洁，可读性强，感兴趣的同学不妨一试。

#### [ViewBuilder 研究 —— 掌握 Result builders](https://mp.weixin.qq.com/s/4TwfyhWHVjm3Dv-Vz7MYvg)

@东坡肘子：结果构造器能按顺序构造一组嵌套的数据结构。利用它，可以以一种自然的声明式语法为嵌套数据结构实现一套领域专门语言（ DSL ），SwiftUI 的声明式特性即来源于此。本文将探讨结果构造器的实现原理，以及如何使用它来创建自己的 DSL 。

#### [为自定义属性包装类型添加类 @Published 的能力](https://mp.weixin.qq.com/s/USGJbLnR-l8Ajgcj8Vb7_A) 

@东坡肘子：属性包装器允许你在一个独特的包装器对象中提取通用逻辑。你可以把属性包装器看作是一个额外的层，它定义了一个属性是如何在读取时存储或计算的。它有利于改善 getters 和 setters 中发现重复性代码的几率。本文介绍了 Swift 编译器如何将属性包装类型转译为标准的 Swift 代码，并通过几个实例让读者对属性包装器的用法有更深的了解。

