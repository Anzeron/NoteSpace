### 结构体初始化器

初始化器：要保证所有成员都有初始值

#### 编译器会自动生成一个或者多个初始化器

只生成一个初始化器

```swift
struct Point1 {
    var x: Int
    var y: Int
}
let p1 = Point1(x:1, y: 2)
```

2个初始化器

```swift
struct Point2 {
    var x: Int = 1
    var y: Int
}
let p2 = Point2(x:1, y: 2)
let p3 = Point2(y: 2)
```

可选类型是有默认值`nil`，编译器生成4个

```swift
struct Point3 {
    var x: Int?
    var y: Int?
}
let p4 = Point3(x:1, y: 2)
let p5 = Point3(y: 2)
let p6 = Point3(x:1)
let p7 = Point3()
```

#### 自定义初始化器，编译器不会再自动生成

自定义了初始化器，那就只有一个初始化器了。

```swift
struct Point4 {
    var x: Int = 0
    var y: Int = 0
    init(x: Int, y: Int) {
        self.x = x
        self.y = y
    }
}
let p8 = Point4(x:1, y: 2)
// let p9 = Point4(y: 2) 编译报错
```

#### 编译器生成的初始化器

`Point5`编译器会生成初始化器`init()`，实现跟`Point6`的`init()`是一样的。

通过观察2个地方的汇编代码，发现它们是一样的。

```swift
struct Point5 {
    var x: Int = 0
    var y: Int = 0
}
let p10 = Point5()

struct Point6 {
    var x: Int
    var y: Int
    init() {
        x = 0
        y = 0
    }
}
let p11 = Point6()
```

### 类初始化器

#### 编译器不会生成带参数的初始化器

以下代码会编译出错，提示没有初始化器。

```swift
class Point7 {
    var x: Int
    var y: Int
}
```

#### 编译器生成无参初始化器

如果所有的成员变量在定义时都有初始值，编译器会自动生成无参初始化器。

```swift
class Point8 {
    var x: Int = 1
    var y: Int = 2
}
let p12 = Point8()
//let p13 = Point8(x: 1, y: 2)
```
