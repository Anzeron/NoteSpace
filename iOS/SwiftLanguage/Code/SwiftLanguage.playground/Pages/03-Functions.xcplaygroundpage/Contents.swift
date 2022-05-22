//: [Previous](@previous)

import Foundation

func someFunction(a: Int = 1, b: Int ) {
    
}
someFunction(a: 3, b: 6)
someFunction(b: 4)

func someFunction2(_ a: Int = 1, b: Int, _ c: Int = 2 ) {
    
}
someFunction2(b: 1)

@inline(never) func test() -> Void {
    
}



// Variadic Parameters
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

// inout
func swapTwoInts(_ a: inout Int, _ b: inout Int) {
    let temporaryA = a
    a = b
    b = temporaryA
}

var a = 3
var b = [1,2]
swapTwoInts(&a,&(b[1]))
print(a,b)

// 函数重载
func sum(v1: Int, v2: Int) -> Int {
    v1 + v2
}

func sum(v1: Int, v2: Int, v3: Int = 10) -> Int {
    v1 + v2 + v3
}

func sum(_ v1: Int, _ v2: Int) -> Int {
    v1 + v2
}

func sum(_ numbers: Int...) -> Int {
    var total = 0
    for number in numbers {
        total += number
    }
    return total
}

sum(v1: 10, v2: 20)


func chooseStepFunction(backward: Bool) -> (Int) -> Int {
    func stepForward(input: Int) -> Int { return input + 1 }
    func stepBackward(input: Int) -> Int { return input - 1 }
    return backward ? stepBackward : stepForward
}
chooseStepFunction(backward: true)(2)
chooseStepFunction(backward: false)(1)


//: [Next](@next)
