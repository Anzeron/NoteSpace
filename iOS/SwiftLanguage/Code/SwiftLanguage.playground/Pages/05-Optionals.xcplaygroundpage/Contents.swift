//: [Previous](@previous)

import Foundation

var greeting: String? = "Hello, playground"
print(greeting)

var age: Int? = 1
print(age!)
age = nil
if age != nil {
    print(age!)
}

var possibleNumber = "12"
if let actualNumber = Int(possibleNumber) {
    print("The string \"\(possibleNumber)\" has an integer value of \(actualNumber)")
} else {
    print("The string \"\(possibleNumber)\" couldn't be converted to an integer")
}

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
var strs = ["12","ab"]
var i = 0
while let num = Int(strs[i]),
    num > 0 {
    print("num in strs: " + "\(num)")
    i += 1
}

let a1: Int? = nil
let b1: Int? = 1
let c1 = a1 ?? b1    // Optional(1)

let a: Int? = nil
let b: Int? = 1
// a != nil || b != nil
if let c = a ?? b {
    print(c)
}

let a2: Int? = 2
let b2: Int = 1
let c2 = a2 ?? b2    // 2
print(c2)

let num1: Int? = 1
let num2: Int?? = num1
let num3: Int?? = 1
print(num2 == num3) // true

let num4: Int? = nil
let num5: Int?? = num4  // not nil，有一个值num4
let num6: Int?? = nil
print(num5) // Optional(nil)
print(num5 == num6) // false





//: [Next](@next)
