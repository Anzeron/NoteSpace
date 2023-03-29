[toc]

Subscripts can be defined in:

- class
- structure
- enumeration

Youcan define multiple subscripts

-  the appropriate subscript overload to use is selected based on the type of index value you pass to the subscript.

you can define subscripts with multiple input parameters

### Subscript Syntax

get and set

```swift
subscript(index: Int) -> Int {
    get {
        // Return an appropriate subscript value here.
    }
    set(newValue) {
        // Perform a suitable setting action here.
    }
}
```

read only

```swift
subscript(index: Int) -> Int {
    // Return an appropriate subscript value here.
} 
```

multiple parameters

```swift
struct Matrix {
    let rows: Int, columns: Int
    var grid: [Double]
    init(rows: Int, columns: Int) {
        self.rows = rows
        self.columns = columns
        grid = Array(repeating: 0.0, count: rows * columns)
    }
    func indexIsValid(row: Int, column: Int) -> Bool {
        return row >= 0 && row < rows && column >= 0 && column < columns
    }
    subscript(row: Int, column: Int) -> Double {
        get {
            assert(indexIsValid(row: row, column: column), "Index out of range")
            return grid[(row * columns) + column]
        }
        set {
            assert(indexIsValid(row: row, column: column), "Index out of range")
            grid[(row * columns) + column] = newValue
        }
    }
}

var matrix = Matrix(rows: 2, columns: 2)
matrix[0, 1] = 1.5
```



### Type Subscripts

`static`

- can not override

`class`

- can override

```swift
enum SubPlanet: Int {
    case mercury = 1, venus, earth, mars, jupiter, saturn, uranus, neptune
    static subscript(n: Int) -> SubPlanet {
        return SubPlanet(rawValue: n)!
    }
}
```