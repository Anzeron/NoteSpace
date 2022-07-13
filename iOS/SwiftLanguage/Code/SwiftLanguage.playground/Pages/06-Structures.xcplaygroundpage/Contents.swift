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

struct Point5 {
    var x: Int = 0
    var y: Int = 0
}
let p10 = Point5()

struct Point6 {
    var x: Int
    var y: Int
    init() {
        x = 0
        y = 0
    }
}
let p11 = Point6()

//class Point7 {
//    var x: Int
//    var y: Int
//}
//let p12 = Point7(x: 1, y: 2)

class Point8 {
    var x: Int = 1
    var y: Int = 2
}
let p12 = Point8()
//let p13 = Point8(x: 1, y: 2)

class_getInstanceSize(Point8.self)
let p14 = p12

if p14 === p12 {
    print("p14 === p12")
}

struct Point9 {
    var x: Int
    var b1: Bool
    var b2: Bool
    var y: Int
}
MemoryLayout<Point9>.size  // 24
MemoryLayout<Point9>.stride    // 24
MemoryLayout<Point9>.alignment     // 8

class Point10 {
    var x: Int
    var b1: Bool
    var b2: Bool
    var y: Int
    init(x: Int, b1: Bool, b2: Bool, y: Int) {
        self.x = x
        self.b1 = b1
        self.b2 = b2
        self.y = y
    }
}
MemoryLayout<Point10>.size  // 8
MemoryLayout<Point10>.stride    // 8
MemoryLayout<Point10>.alignment     // 8

let p15 = Point10(x: 1, b1: true, b2: false, y: 2)
MemoryLayout.size(ofValue: p15)     // 8
MemoryLayout.stride(ofValue: p15)   // 8
MemoryLayout.alignment(ofValue: p15)    // 8





//: [Next](@next)
