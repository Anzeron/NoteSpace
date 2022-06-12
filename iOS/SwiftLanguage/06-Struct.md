### 初始化器

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

#### 

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

