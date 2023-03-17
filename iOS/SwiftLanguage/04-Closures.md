### 闭包的定义

闭包和函数的关系



闭包类型，闭包是引用类型。

```swift
(parameters) -> return type

// 比如
(s1: String, s2: String) -> Bool
```

闭包表达式

```swift
{ (parameters) -> return type in
    statements
}

// 比如
let backword: (String,String) -> Bool = {
    (s1: String, s2: String) -> Bool in
        return s1 > s2
}
```



### 尾随闭包

一个函数的最后一个参数是闭包类型，那么调用这个函数，可以进行如下简化：

- 不用写最后一个参数标签；闭包表达式，可以写在函数`()`外
- 如果只有唯一的闭包类型参数，调用这个函数可以把`()`省略

```swift
// 函数闭包
func someFunctionThatTakesAClosure(age: Int, closure: () -> Void) {
    closure()
}

func someFunctionThatTakesAClosure2(closure: () -> Void) {
    closure()
}

// 以下是多种方式调用
someFunctionThatTakesAClosure(age:1, closure: {
    print("trailing closure 1")
})

someFunctionThatTakesAClosure(age:1) {
    print("trailing closure 2")
}

someFunctionThatTakesAClosure2 {
    print("trailing closure 3")
}
```



一个函数的最后几个参数都是闭包类型，调用方式可以继续变化。

```swift
// 尾随闭包，函数最后2个或者多个参数是闭包
func loadPicture(from serverName: String, completion: () -> Void, onFailure: () -> Void) {
    if serverName == "success" {
        completion()
    } else {
        onFailure()
    }
}

// 函数调用
loadPicture(from: "success") {
    print("loadPicture success")
} onFailure: {
    print("loadPicture fail")
}

loadPicture(from: "fail") {
    print("loadPicture success")
} onFailure: {
    print("loadPicture fail")
}
```



### 值捕获

闭包可以在其被定义的上下文中`捕获常量或变量`。即使定义这些常量和变量的原作用域已经不存在，闭包仍然可以在闭包函数体内引用和`修改`这些值。

- 可以修改捕获的变量，不需要特殊操作

为了优化，如果一个值不会被闭包改变，或者在闭包创建后不会改变，Swift 可能会改为捕获并保存一份对值的拷贝。

Swift 也会负责被捕获变量的所有内存管理工作，包括释放不再需要的变量。

```swift
func makeIncrementer(forIncrement amount: Int) -> (() -> Int) {
    var runningTotal = 0
    func incrementer() -> Int {
        runningTotal += amount
        return runningTotal
    }
    return incrementer
}

let incrementByTen = makeIncrementer(forIncrement: 10)
incrementByTen()
incrementByTen()

let incrementByOne = makeIncrementer(forIncrement: 1)
incrementByOne()
incrementByOne()
```



### 逃逸闭包

当一个闭包作为参数传到一个函数中，但是这个闭包在函数返回之后才被执行，我们称该闭包从函数中`逃逸`。

在闭包参数类型前面，加上`@escaping`，表明这是一个逃逸闭包。

```swift
var completionHandlers: [() -> Void] = []
func someFunctionWithEscapingClosure(completionHandler: @escaping () -> Void) {
    completionHandlers.append(completionHandler)
}
```



逃逸闭包，需要显式地引用 `self`

非逃逸闭包，可以隐式引用 `self`

```swift
func someFunctionWithNonescapingClosure(closure: () -> Void) {
    closure()
}

class SomeClass {
    var x = 10
    func doSomething() {
        someFunctionWithEscapingClosure { self.x = 100 }
        someFunctionWithNonescapingClosure { x = 200 }
    }
}
```

### 自动闭包

如果一个函数参数是闭包，闭包也不接受任何参数，那么可以将一个表达式传给这个参数，表达式会被自动创建成闭包，这就是自动闭包。

这种便利语法让你能够省略闭包的花括号，用一个普通的表达式来代替显式的闭包。

自动闭包能够延迟求值，因为直到调用这个闭包，代码段才会被执行。延迟求值对于那些有副作用（Side Effect）和高计算成本的代码来说是很有益处的，因为它使得你能控制代码的执行时机。

`assert(condition:message:file:line:)` 函数接受自动闭包作为它的 `condition` 参数和 `message` 参数；它的 `condition` 参数仅会在 debug 模式下被求值，它的 `message` 参数仅当 `condition` 参数为 `false` 时被计算求值



使用`@autoclosure`标记自动闭包。

```swift
var customersInLine = ["Chris", "Alex", "Ewa", "Barry", "Daniella"]

func serve(customer customerProvider: @autoclosure () -> Void) {
    print("Now serving \(customerProvider())!")
}
serve(customer: customersInLine.append("haha"))

func serve2(customer customerProvider: @autoclosure () -> String) {
    print("Now serving2 \(customerProvider())!")
}
serve2(customer: customersInLine.remove(at: 0))
```



`@autoclosure`和`@escaping`可以同时使用。

```swift
var customersInLine = ["Chris", "Alex", "Ewa", "Barry", "Daniella"]
var customerProviders: [() -> String] = []
func collectCustomerProviders(_ customerProvider: @autoclosure @escaping () -> String) {
    customerProviders.append(customerProvider)
}
collectCustomerProviders(customersInLine.remove(at: 0))
collectCustomerProviders(customersInLine.remove(at: 0))
```





