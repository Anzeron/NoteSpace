//: [Previous](@previous)

import Foundation

func sum(_ v1: Int, _ v2: Int) -> Int {
    return v1 + v2
}

var f1 = sum
f1(1,2)

let names = ["Chris", "Alex", "Ewa", "Barry", "Daniella"]

func backward(_ s1: String, _ s2: String) -> Bool {
    return s1 > s2
}
var reversedNames = names.sorted(by: backward)


//: [Next](@next)
