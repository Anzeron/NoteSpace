[toc]

Properties

- Stored properties , store constant and variable values. provided  by 
  - classes 
  - structures
- Computed properties,  calculate (rather than store) a value. provided  by 
  - classes 
  - structures
  - enumerations

### Stored Properties

Stored properties can be 

- either variable stored properties , introduced by the ``var`` keyword)
- constant stored properties , introduced by the ``let`` keyword

```swift
struct FixedLengthRange {
    var firstValue: Int
    let length: Int
}
```

Lazy Stored Properties

indicate a lazy stored property by writing the lazy modifier before its declaration.

```swift
class PropDataManager {
    lazy var importer = PropDataImporter()
    var data = [String]()
    // 代码块只执行一次
    lazy var dataName: String = {
        if data.capacity > 0 {
            return "data is full"
        }
        return "date is empty"
    }()
    init() {
        print("PropDataManager inited")
        print("PropDataManager access importer")
        print("importer file name: " + importer.filename)
        print("dataName : " + dataName)
    }
}
```

### Computed Properties 

Computed Properties provide

- getter
- an optional setter

```swift
struct PropPoint {
    var x = 0.0, y = 0.0
}
struct PropSize {
    var width = 0.0, height = 0.0
}
struct PropRect {
    var origin = PropPoint()
    var size = PropSize()
    var center: PropPoint {
        get {
            let centerX = origin.x + (size.width / 2)
            let centerY = origin.y + (size.height / 2)
            return PropPoint(x: centerX, y: centerY)
        }
        // 推荐使用这种样式
        set(newCenter) {
            origin.x = newCenter.x - (size.width / 2)
            origin.y = newCenter.y - (size.height / 2)
        }
    }
    
    // readonly computed property
    var area:Double {
        return size.width * size.height
    }
}

struct PropAlternativeRect {
    var origin = PropPoint()
    var size = PropSize()
    var center: PropPoint {
        get {
            let centerX = origin.x + (size.width / 2)
            let centerY = origin.y + (size.height / 2)
            return PropPoint(x: centerX, y: centerY)
        }
        set {
            // 使用newValue
            origin.x = newValue.x - (size.width / 2)
            origin.y = newValue.y - (size.height / 2)
        }
    }
}
```

### Property Observers

You can add property observers in the following places:

- Stored properties that you define

- Stored properties that you inherit

- Computed properties that you inherit

You have the option to define either or both of these observers on a property:

- willSet is called just before the value is stored. with a default parameter name of ``newValue``.

- didSet is called immediately after the new value is stored. with a default parameter name of ``oldValue``

```swift
class PropStepCounter {
    var totalSteps: Int = 0 {       // stored property
        willSet(newTotalSteps) {
            print("About to set totalSteps to \(newTotalSteps)")
        }
        didSet {
            if totalSteps > oldValue  {
                print("Added \(totalSteps - oldValue) steps")
            }
        }
    }
}
```

### Property Wrappers

Wrapper: adds a layer of separation between code that manages how a property is stored and the code that defines a property.

projected value:  can expose additional functionality

```swift
@propertyWrapper
struct PropTwelveOrLess {
    private var number: Int
    // projectedValue can be any type.
    // Here projectedValue means number be set with newValue or not
    var projectedValue: Bool
    init() {
        self.number = 0
        self.projectedValue = true
    }
    var wrappedValue: Int {
        get { return number }
        set {
            if newValue > 12 {
                number = 12
                self.projectedValue = false
            } else {
                number = newValue
                self.projectedValue = true
            }
        }
    }
}
```

Initial

```swift
@propertyWrapper
struct PropSmallNumber {
    private var maximum: Int
    private var number: Int

    var wrappedValue: Int {
        get { return number }
        set { number = min(newValue, maximum) }
    }

    init() {
//        self.init(wrappedValue:0)
        print("propertyWrapper PropSmallNumber init() ")
        maximum = 12
        number = 0
    }
    init(wrappedValue: Int) {
//        self.init(wrappedValue: wrappedValue, maximum: 12)
        print("propertyWrapper PropSmallNumber init(wrappedValue: Int)")
        maximum = 12
        number = min(wrappedValue, maximum)
    }
    init(wrappedValue: Int, maximum: Int) {
        print("propertyWrapper PropSmallNumber init(wrappedValue: Int, maximum: Int)")
        self.maximum = maximum
        number = min(wrappedValue, maximum)
    }
}

//Initial Values for Wrapped Properties
struct PropSmallRectangle {
    @PropTwelveOrLess var height: Int
    @PropTwelveOrLess var width: Int
    @PropSmallNumber var height2: Int   // init()
    @PropSmallNumber var height3: Int = 2       // init(wrappedValue: Int)
    @PropSmallNumber(wrappedValue: 2, maximum: 5) var height4: Int  // init(wrappedValue: Int, maximum: Int)
    @PropSmallNumber(maximum: 9) var height5: Int = 4   // init(wrappedValue: Int, maximum: Int)
    // 编译不过
//    @PropSmallNumber(wrappedValue: 2, maximum: 5) var height6: Int = 4
}
```

### Type property

`static`

- stored Property
- computed property
- can not override

`class`

- computed property
- can override

```swift
class PropStructure {
    static var storedTypeProperty = "Some value."
    static var computedTypeProperty: Int {
        return 1
    }
    
    class var name: String {
        return "PropStructure"
    }
    
    // 不支持 class stored property
//    class var age: Int = 2
}

class PropSubStructure: PropStructure {
    class override var name: String {
        let superName = super.name;
        return "son + " + superName
    }
}		
```