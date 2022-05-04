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

  ```swift
  // 需要设置明确的结束点
  for i in 1... {
      print(i)
  }
  ```

字符和字符串也能使用区间运算符，但默认不能用于for循环。

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

`case`后面，使用逗号`,`将多个匹配值分开

```swift
let anotherCharacter: Character = "a"
switch anotherCharacter {
case "a", "A":
    print("The letter A")
default:
    print("Not the letter A")
}
```





### 

