//: [Previous](@previous)

import Foundation

for i in 1...3 {
    print(i)
}

for i in 1..<3 {
    print(i)
}

// 需要注意，必须要有结束点
//for i in 1... {
//    print(i)
//}

let r1 = 1...3
print(r1)

// 字符串也能使用区间运算符，默认不能用于for循环
let r2 = "a"..."c"
print(r2)
//for a in r2 {
//    print(a)
//}

//: ### switch

let someCharacter: Character = "z"
switch someCharacter {

case "a":
    print("The first letter of the alphabet")
    
case "z":
    print("The last letter of the alphabet")
    
default:
    print("Some other character")
    
}

// 复合语句
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

// 区间匹配
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

// 元组匹配
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

// 值绑定
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

// where
let yetAnotherPoint = (1, -1)
switch yetAnotherPoint {
case let (x, y) where x == y:
    print("(\(x), \(y)) is on the line x == y")
case let (x, y) where x == -y:
    print("(\(x), \(y)) is on the line x == -y")
case let (x, y):
    print("(\(x), \(y)) is just some arbitrary point")
}

var numbers = [10, 20, -10, -20, 30, -30]
var sum = 0
// 使用where来过滤num
for num in numbers where num > 0 {
    sum += num
}
print(sum) // 60

// statement label
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

 



//: [Next](@next)
