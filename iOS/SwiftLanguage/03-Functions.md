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

- 可以使用`_`省略参数标签

  ```swift
  func sum(_ v1: Int, _ v2: Int) -> Int {
      v1 + v2
  }
  sum(1,2)
  ```



#### 默认参数值

- 参数可以有默认值，由于存在参数标签，一般情况下参数都可以有默认值

  ```swift
  func someFunction(a: Int = 1, b: Int ) {
      
  }
  someFunction(a: 3, b: 6)
  someFunction(b: 4)
  ```

- 同时使用默认参数值和**省略参数标签**时，调用的时候要注意写参数标签，保证所有参数都有值

  ```swift
  func someFunction2(_ a: Int = 1, b: Int, _ c: Int = 2 ) {
      
  }
  // 必须写参数标签
  someFunction2(b: 1)
  ```

  

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

  

### 函数重载

2个函数需要满足以下条件

- 函数名相同
- 参数个数不同，或者参数类型不同，或者参数标签不同

注意点

- 返回值类型与函数重载无关

- 默认参数值和函数重载一起使用不会产生二义性。这个不好

  ```swift
  func sum(v1: Int, v2: Int) -> Int {
      v1 + v2
  }
  
  func sum(v1: Int, v2: Int, v3: Int = 10) -> Int {
      v1 + v2 + v3
  }
  sum(v1: 10, v2:20) // 使用第一个函数
  ```

- 可变参数，省略参数，函数重载一起使用，很奇怪现象，别这样搞

  ```swift
  func sum(v1: Int, v2: Int) -> Int {
      v1 + v2
  }
  
  func sum(v1: Int, v2: Int, v3: Int = 10) -> Int {
      v1 + v2 + v3
  }
  
  func sum(_ numbers: Int...) -> Int {
      var total = 0
      for number in numbers {
          total += number
      }
      return total
  }
  ```




### 内联函数

- 将函数调用展开成函数体内容，避免函数的栈开销
- 编译器会进行优化。在Release模式下默认开启优化，Debug模式下没有优化



哪些函数不会被自动内联

- 函数体比较长。可能会影响包体积
- 函数体内有递归调用
- 函数体内有动态派发



内敛关键字`inline`。编译器会自动优化，其实没有必要用

```swift
 // 永远不会被内联(即使开启了编译器优化) 
@inline(never) func test1() {
    print("test")
}

// 开启编译器优化后，即使代码很长，也会被内联(递归调用函数、动态派发的函数除外) 
@inline(__always) func test() { 								`    
	print("test") 
}
```



### 函数类型

函数类型由2部分组成

- 参数类型
- 返回类型

```swift
// () -> ()
func printHelloWorld() {
    print("hello, world")
}

// (Int, Int) -> Int
func addTwoInts(_ a: Int, _ b: Int) -> Int {
    return a + b
}
```



#### 作为变量的类型

变量或者常量都可以

```swift
var mathFunction: (Int, Int) -> Int = addTwoInts
print("Result: \(mathFunction(2, 3))")
```



#### 作为参数的类型

```swift
func printMathResult(_ mathFunction: (Int, Int) -> Int, _ a: Int, _ b: Int) {
    print("Result: \(mathFunction(a, b))")
}
printMathResult(addTwoInts, 3, 5)
```



#### 作为返回的类型

```swift
func stepForward(_ input: Int) -> Int {
    return input + 1
}

func stepBackward(_ input: Int) -> Int {
    return input - 1
}

func chooseStepFunction(backward: Bool) -> (Int) -> Int {
    return backward ? stepBackward : stepForward
}
```



### 嵌套函数

```swift
func chooseStepFunction(backward: Bool) -> (Int) -> Int {
    func stepForward(input: Int) -> Int { return input + 1 }
    func stepBackward(input: Int) -> Int { return input - 1 }
    return backward ? stepBackward : stepForward
}
chooseStepFunction(backward: true)(2)
chooseStepFunction(backward: false)(1)
```









