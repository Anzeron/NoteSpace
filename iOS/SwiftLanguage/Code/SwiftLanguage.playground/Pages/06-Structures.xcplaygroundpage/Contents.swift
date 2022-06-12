//: [Previous](@previous)

import Foundation

struct Point1 {
    var x: Int
    var y: Int
}
let p1 = Point1(x:1, y: 2)

struct Point2 {
    var x: Int = 1
    var y: Int
}
let p2 = Point2(x:1, y: 2)
let p3 = Point2(y: 2)

struct Point3 {
    var x: Int?
    var y: Int?
}
let p4 = Point3(x:1, y: 2)
let p5 = Point3(y: 2)
let p6 = Point3(x:1)
let p7 = Point3()

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



//: [Next](@next)
