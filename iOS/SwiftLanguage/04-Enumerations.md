### Syntax

introduce enumerations with the ``enum`` keyword

```swift
enum SomeEnumeration {
    // enumeration definition goes here
} 
```

use the ``case``  keyword to introduce new enumeration cases

```swift
enum CompassPoint {
    case north
    case south
    case east
    case west
}

enum Planet {
    case mercury, venus, earth, mars, jupiter, saturn, uranus, neptune
}
```

Define a var with enum type

```swift
var directionToHead = CompassPoint.west
directionToHead = .east
```

#### Matching Enumeration Values

- with a Switch Statement
- with a if statement

```swift
let somePlanet = Planet.earth
switch somePlanet {
case .earth:
    print("Mostly harmless")
default:
    print("Not a safe place for humans")
}
// Prints "Mostly harmless”

if somePlanet == .earth {
    print("Planet.earth self: " + "\(somePlanet)")
}
```

#### Iterating over Enumeration Cases

it’s useful to have a collection of all of that enumeration’s cases. 

You enable this by writing : ``CaseIterable`` after the enumeration’s name.

```swift
enum Beverage: CaseIterable {
    case coffee, tea, juice
}
let numberOfChoices = Beverage.allCases.count
print("\(numberOfChoices) beverages available")
// Prints "3 beverages available”

for beverage in Beverage.allCases {
    print(beverage)
}
// coffee
// tea
// juice”
```

### Associated Values

Enumeration cases can specify associated values of any type to be stored along with each different case value.

it varies each time you use that case as a value in your code.

You extract each associated value as a constant (with the let prefix) or a variable (with the var prefix) for use within the switch case’s body:

```swift
enum Barcode {
    case upc(Int, Int, Int, Int)
    case qrCode(String)
}

var productBarcode = Barcode.upc(8, 85909, 51226, 3)
switch productBarcode {
case .upc(let numberSystem, let manufacturer, let product, let check):
    print("UPC: \(numberSystem), \(manufacturer), \(product), \(check).")
case .qrCode(let productCode):
    print("QR code: \(productCode).")
}
```

if all are extracted as variables, you can place a single var or let annotation before the case name, for brevity:

```swift
switch productBarcode {
case let .upc(numberSystem, manufacturer, product, check):
    print("UPC : \(numberSystem), \(manufacturer), \(product), \(check).")
case let .qrCode(productCode):
    print("QR code: \(productCode).")
}
// Prints "QR code: ABCDEFGHIJKLMNOP.”
```

#### note

Can not match enumeration case with a if statement if has associated value

can not  both use `CaseIterable` and `Associated Values`

### Raw value

Each raw value must be unique within its enumeration declaration. Raw values can be

- strings
- characters
- integer or floating-point

You should specify raw value type in declaration if you want to use raw value.

```swift
enum CompassPoint: Int {
    case north = 1
    case south = 2
    case east = 3
    case west = 4
}

let p1 = CompassPoint.south
print("CompassPoint.south self: " + "\(p1)")
print("CompassPoint.south rawValue: " + "\(p1.rawValue)")
```

you can both use `CaseIterable` and `Raw value`

```swift
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
```

#### Implicitly Assigned Raw Values

Swift automatically assigns the values for you with above type

- integer
- String

The implicit rule is:

- Integer: each case is one more than the previous case. If the first case doesn’t have a value set, its value is 0.
- String:  the implicit value for each case is the text of that case’s name.

```swift
enum Planet: Int {
    case mercury = 1, venus, earth, mars, jupiter, saturn, uranus, neptune
}

let p2 = Planet.venus
print("Planet.venus self: " + "\(p2)")
print("Planet.venus rawValue: " + "\(p2.rawValue)")

enum Zimu: String {
    case A = "a"
    case B
    case C
}
let z2 = Zimu.B
print("Zimu.B self: " + "\(z2)")
print("Zimu.B rawValue: " + "\(z2.rawValue)")
```

#### Initializing from a Raw Value

the enumeration automatically receives an initializer that takes a value of the raw value’s type (as a parameter called rawValue)

the raw value initializer always returns an ``optional enumeration case``

```swift
let positionToFind = 11
if let somePlanet = Planet(rawValue: positionToFind) {
    switch somePlanet {
    case .earth:
        print("Mostly harmless")
    default:
        print("Not a safe place for humans")
    }
} else {
    print("There isn't a planet at position \(positionToFind)")
} 
```

### Recursive Enumerations

A recursive enumeration is an enumeration that has another instance of the enumeration as the associated value for one or more of the enumeration cases. 

You indicate that an enumeration case is recursive by writing `indirect` before it, which tells the compiler to insert the necessary layer of indirection.

```swift
enum ArithmeticExpression {
    case number(Int)
    indirect case addition(ArithmeticExpression, ArithmeticExpression)
    indirect case multiplication(ArithmeticExpression, ArithmeticExpression)
}
```

```swift
indirect enum ArithmeticExpression {
    case number(Int)
    case addition(ArithmeticExpression, ArithmeticExpression)
    case multiplication(ArithmeticExpression, ArithmeticExpression)
}
```

### MemoryLayout

枚举，泛型。

```swift
enum Barcode {
    case upc(Int, Int, Int, Int)
    case qrCode(String)
}

enum CompassPoint: Int {
    case north = 1
    case south = 2
    case east = 3
    case west = 4
}
```

获取类型的内存占用

```swift
MemoryLayout<Barcode>.size  // 33，实际使用的字节。最大的是32，还有一个字节用来判断是哪个case
MemoryLayout<Barcode>.stride    // 40，分配的内存
MemoryLayout<Barcode>.alignment     // 8，对齐参数

MemoryLayout<CompassPoint>.size // 1
MemoryLayout<CompassPoint>.stride   // 1，只需要1个字节就能表示所有case
MemoryLayout<CompassPoint>.alignment    // 1
```

获取变量的内存占用

```swift
let barcode = Barcode.upc
MemoryLayout.size(ofValue: barcode)     // 16
MemoryLayout.stride(ofValue: barcode)   // 16
MemoryLayout.alignment(ofValue: barcode)    // 8
```

如果枚举只有一个`case`，类型实际使用的内存是0

```swift
enum Barcode2 {
    case custom
}
MemoryLayout<Barcode2>.size  // 0，实际使用的字节。
MemoryLayout<Barcode2>.stride    // 1，分配的内存
MemoryLayout<Barcode2>.alignment     // 1，对齐参数
```

如果枚举只有一个`case`，并且有关联值，类型实际使用的内存是8，不需要再多1个字节来区分是哪个`case`

```swift
enum Barcode3 {
    case custom(Int)
}
MemoryLayout<Barcode3>.size  // 8，实际使用的字节。不需要再多1个字节来区分是哪个case
MemoryLayout<Barcode3>.stride    // 8，分配的内存
MemoryLayout<Barcode3>.alignment     // 8，对齐参数
```
