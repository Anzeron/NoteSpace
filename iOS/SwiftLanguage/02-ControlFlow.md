### if else

### while

### for

#### 区间运算符

- 闭区间运算符:`a...b`，对应的类型

  ```swift
  for i in 1...3 {
      print(i)
  }
  ```

- 半开区间运算符，只能半开右边区间:`a..<b`

  ```swift
  for i in 1..<3 {
      print(i)
  }
  ```

- 单侧区间: `a...`, `...a`, `..<b`,

  - `...a`, `..<b`不能进行循环，因为不知道起点是什么
  - `a...`,可以循环，但是需要明确的结束点
  
  ```swift
  // 需要设置明确的结束点
  for i in 1... {
      print(i)
  }
  ```



字符和字符串也能使用区间运算符，但默认不能用于for循环。

```swift
let r2 = "a"..."c"
print(r2)
//for a in r2 {
//    print(a)
//}
```



区间运算符，其实是`Comparable`协议里的方法

```swift
static func ..< (minimum: Self, maximum: Self) -> Range<Self>

static func ... (minimum: Self, maximum: Self) -> ClosedRange<Self>

postfix static func ... (minimum: Self) -> PartialRangeFrom<Self>

prefix static func ... (maximum: Self) -> PartialRangeThrough<Self>

prefix static func ..< (maximum: Self) -> PartialRangeUpTo<Self>
```



#### 区间的类型

- `ClosedRange`: `ClosedRange<Int>`, 比如`1...3`
- `Range`:`Range<Int>`,比如`1..<3`
- `PartialRangeThrough`:`PartialRangeThrough<Int>`,比如`...5`
- `PartialRangeFrom`:`PartialRangeFrom<Int>`,比如`1...`
- `PartialRangeUpTo`:`PartialRangeUpTo<Int>`,比如`..<4`



### switch

#### 基本注意点

- `case`, `default`后面不能写`{}`，会报错

- `case`, `default`最后可以不用写`break`，默认不执行后面的`case`

- 必须要保证能处理所有情况

  - 要么处理了所有枚举值
  - 要么使用`default`

- `case`, `default`后面至少要有一条语句

  - 可以只写一个`break`

- 还支持字符`Character`和字符串`String`

  ```swift
  let someCharacter: Character = "z"
  switch someCharacter {
  
  case "a":
      print("The first letter of the alphabet")
      
  case "z":
      print("The last letter of the alphabet")
      
  default:
      print("Some other character")
      
  }
  ```

  

#### 多个匹配

匹配多个值，可以使用以下方法：

- `case`后面，使用逗号`,`将多个匹配值分开
- 使用`fallthrough`，跳到下一个`case`

```swift
let anotherCharacter: Character = "b"
switch anotherCharacter {
case "a", "A":
    print("The letter A")
case "b":
    fallthrough
case "B":
    print("The letter B")
default:
    print("Not the letter A")
}
```



#### 区间匹配

```swift
let approximateCount = 62
let countedThings = "moons orbiting Saturn"
let naturalCount: String
switch approximateCount {
case 0:
    naturalCount = "no"
case 1..<5:
    naturalCount = "a few"
case 5..<12:
    naturalCount = "several"
case 12..<100:
    naturalCount = "dozens of"
case 100..<1000:
    naturalCount = "hundreds of"
default:
    naturalCount = "many"
}
print("the naturalCount is \(naturalCount)")
```

#### 元组匹配

```swift
let somePoint = (1, 1)
switch somePoint {
case (0, 0):
    print("\(somePoint) is at the origin")
case (_, 0):
    print("\(somePoint) is on the x-axis")
case (0, _):
    print("\(somePoint) is on the y-axis")
case (-2...2, -2...2):
    print("\(somePoint) is inside the box")
default:
    print("\(somePoint) is outside of the box")
}
```

#### 值绑定

可以使用`let`或者`var`

```swift
let anotherPoint = (2, 0)
switch anotherPoint {
case (let x, 0):
    print("on the x-axis with an x value of \(x)")
case (0, let y):
    print("on the y-axis with a y value of \(y)")
case let (x, y):
    print("somewhere else at (\(x), \(y))")
}
// Prints "on the x-axis with an x value of 2”
```



### where

#### 用于for

```swift
var numbers = [10, 20, -10, -20, 30, -30]
var sum = 0
// 使用where来过滤num
for num in numbers where num > 0 {
    sum += num
}
print(sum) // 60
```



#### 用于switch

```
let yetAnotherPoint = (1, -1)
switch yetAnotherPoint {
case let (x, y) where x == y:
    print("(\(x), \(y)) is on the line x == y")
case let (x, y) where x == -y:
    print("(\(x), \(y)) is on the line x == -y")
case let (x, y):
    print("(\(x), \(y)) is just some arbitrary point")
}


```



### statement label

在多重循环里，可以使用标签

- 使用标签，标识一重循环，一般是外面的循环
- 内部循环，可以使用`continue`和`break`操作该标签

```swift
outer: for i in 1...4 {
    for k in 1...4 {
        if k == 3 {
            continue outer
        }
        if i == 3 {
            break outer
        }
        print("i == \(i), k == \(k)")
    }
}
```

