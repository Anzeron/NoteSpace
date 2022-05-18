### 函数的定义

参数默认是`let`

```swift
func greet(person: String) -> String {
    let greeting = "Hello, " + person + "!"
    return greeting
}
```



### 函数的返回值

#### 隐式返回值



#### 多返回值

- 使用元组实现多返回值



### 函数的参数

#### 参数标签

- 参数是函数内部使用
- 在外部，调用函数需要参数标签

```swift
func greet(person: String, from hometown: String) -> String {
    return "Hello \(person)!  Glad you could visit from \(hometown)."
}
print(greet(person: "Bill", from: "Cupertino"))
```



#### 默认参数值



#### 可变参数

- 函数最多只能有1个可变参数，不要求是最后一个参数
- 跟在可变参数后面的参数，不能省略参数标签

```swift
func arithmeticMean(_ numbers: Double...) -> Double {
    var total: Double = 0
    print(numbers)
    for number in numbers {
        total += number
    }
    return total / Double(numbers.count)
}
arithmeticMean(1, 2, 3, 4, 5)
// returns 3.0, which is the arithmetic mean of these five numbers
```



#### 输入输出参数

`inout`，可以在函数内部修改外部实参的值

- 可变参数不能标记成`inout`

- 不能有默认值

- 实参必须能被多次赋值

  - 比如普通变量
  - 数组的某个元素

- 本质是地址传递（引用传递）

  ```swift
  func swapTwoInts(_ a: inout Int, _ b: inout Int) {
      let temporaryA = a
      a = b
      b = temporaryA
  }
  var a = 3
  var b = [1,2]
  swapTwoInts(&a,&(b[1]))
  ```

  











