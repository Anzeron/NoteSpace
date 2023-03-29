[TOC]

method can be defined in:

- class
- structure
- enumeration

### Instance method

`mutating` instance method

- Modifying Value Types from Within Instance Methods
- Assigning to self Within a Mutating Method

```swift
struct MePoint {
    var x = 0.0, y = 0.0
    
    // modify property
    mutating func moveBy(x deltaX: Double, y deltaY: Double) {
        x += deltaX
        y += deltaY
    }
    
    // modify self
    mutating func moveBy2(x deltaX: Double, y deltaY: Double) {
        self = MePoint(x: x + deltaX, y: y + deltaY)
    }
}
```

### Type method

`static`

- can not override

`class`

- can override