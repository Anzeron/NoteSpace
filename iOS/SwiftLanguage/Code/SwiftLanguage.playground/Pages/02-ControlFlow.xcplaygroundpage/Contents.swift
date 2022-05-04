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

let anotherCharacter: Character = "a"
switch anotherCharacter {
case "a", "A":
    print("The letter A")
default:
    print("Not the letter A")
}


//: [Next](@next)
