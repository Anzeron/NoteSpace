在类型后面加上`?`定义可选类型

```swift
var greeting: String? = "Hello, playground"
print(greeting)
```

### GetValue

#### 强制解包Forced Unwrapping

对可选变量使用`！`，进行强制解包

如果可选变量是`nil`,程序会崩溃

```swift
var age: Int? = 1
print(age!)
age = nil
if age != nil {
    print(age!)
}
```



#### 值绑定Optional Binding

使用`if`，将可选变量的值绑定到一个常量(`let`)或者变量(`var`)

```swift
var possibleNumber = "12"
if let actualNumber = Int(possibleNumber) {
    print("The string \"\(possibleNumber)\" has an integer value of \(actualNumber)")
} else {
    print("The string \"\(possibleNumber)\" couldn't be converted to an integer")
}
```

`if`的判断条件中，如果有多个值绑定条件，使用`,`表示`&&`

```swift
if let firstNumber = Int("4"),
    let secondNumber = Int("42"),
    firstNumber < secondNumber && secondNumber < 100 {
    print("\(firstNumber) < \(secondNumber) < 100")
}
// Prints "4 < 42 < 100"

if let firstNumber = Int("4") {
    if let secondNumber = Int("42") {
        if firstNumber < secondNumber && secondNumber < 100 {
            print("\(firstNumber) < \(secondNumber) < 100")
        }
    }
}
```

`while`也可以使用值绑定

```swift
var strs = ["12","ab"]
var i = 0
while let num = Int(strs[i]),
    num > 0 {
    print("num in strs: " + "\(num)")
    i += 1
}
```



#### 运算符??

```swift
public func ?? <T>(optional: T?, defaultValue: @autoclosure () throws -> T?) rethrows -> T?
public func ?? <T>(optional: T?, defaultValue: @autoclosure () throws -> T) rethrows -> T
```

`a ?? b`

- a必须是可选项。
- b是可选项或者正常类型
- 返回值类型是跟b保持一致

```swift
let a1: Int? = nil
let b1: Int? = 1
let c1 = a1 ?? b1    // Optional(1)

let a2: Int? = 2
let b2: Int = 1
let c2 = a2 ?? b2    // 2
```

跟`if`配合使用，相当于`||`

```swift
let a: Int? = nil
let b: Int? = 1
// a != nil || b != nil
if let c = a ?? b {
    print(c)
}
```



### guard

```swift
guard 条件 else {
 	// do something....
  退出当前作用域
	// return、break、continue、throw error 
}
```

条件为True，就跳过guard，执行下面的语句

条件为False，就执行guard内的语句

- guard内语句必须有return、break、continue、throw error中的其中一个
- guard 条件的变量或者常量，也存在于guard之后的作用域

```swift
func greet(person: [String: String]) {
    guard let name = person["name"] else {
        return
    }

    print("Hello \(name)!")

    guard let location = person["location"] else {
        print("I hope the weather is nice near you.")
        return
    }

    print("I hope the weather is nice in \(location).")
}
```



### 隐式解包Implicitly Unwrapped Optionals

在类型后面加上`!`定义隐式解包可选类型，也是可选类型

但是会自动解包，如果变量是`nil`，会崩溃

如果确定

```swift
let num: Int! = 1
let num2 = num  // optional
let num3: Int = num // Int
```



### 多重可选项

```swift
let num1: Int? = 1
let num2: Int?? = num1
let num3: Int?? = 1
print(num2 == num3) // true

let num4: Int? = nil
let num5: Int?? = num4  // not nil，有一个值num4
let num6: Int?? = nil
print(num5) // Optional(nil)
print(num5 == num6) // false
```

