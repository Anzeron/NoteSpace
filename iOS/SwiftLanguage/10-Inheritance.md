[toc]

A class can inherit methods, properties, and other characteristics from another class.

### Overriding

`override` keyword

- method
- property
- subscript

Overriding Property Getters and Setters

- an inherited read-only property can be overrided as read-write property
- an inherited read-write property can not be overrided as read-only property

Overriding Property Observers

- can use property overriding to add property observers to an inherited property

- can not override to inherited constant stored properties or inherited read-only computed properties
- cannot provide both an overriding setter and an overriding property observer



### Preventing Overrides

`final`  modifier

- `final` var
- `final` func
- `final` subscript
- `final` class