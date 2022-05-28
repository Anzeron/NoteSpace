//: [Previous](@previous)

import Foundation

enum CompassPoint {
    case north
    case south
    case east
    case west
}
let compass = CompassPoint.north


// rawValue and CaseIterable
enum CompassPoint2: Int, CaseIterable {
    case north = 1
    case south = 2
    case east = 3
    case west = 4
}
let compass2 = CompassPoint2.north
print(compass2.rawValue)
for c in CompassPoint2.allCases {
    print(c)
    print(c.rawValue)
}


enum Barcode {
    case upc(Int, Int, Int, Int)
    case qrCode(String)
}

// 内存占用
MemoryLayout<Barcode>.size  // 33，实际使用的字节。最大的是32，还有一个字节用来判断是哪个case
MemoryLayout<Barcode>.stride    // 40，分配的内存
MemoryLayout<Barcode>.alignment     // 8，对齐参数

let barcode = Barcode.upc
MemoryLayout.size(ofValue: barcode)     // 16
MemoryLayout.stride(ofValue: barcode)   // 16
MemoryLayout.alignment(ofValue: barcode)    // 8

MemoryLayout<CompassPoint2>.size // 1
MemoryLayout<CompassPoint2>.stride   // 1
MemoryLayout<CompassPoint2>.alignment    // 1


//: [Next](@next)
