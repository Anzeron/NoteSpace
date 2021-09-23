### 1 字典中包含``infinity``，使用NSJSONSerialization会崩溃

使用``isValidJSONObject:``，校验字典是否合法

```objc
/* Returns YES if the given object can be converted to JSON data, NO otherwise. The object must have the following properties:
    - Top level object is an NSArray or NSDictionary
    - All objects are NSString, NSNumber, NSArray, NSDictionary, or NSNull
    - All dictionary keys are NSStrings
    - NSNumbers are not NaN or infinity
 Other rules may apply. Calling this method or attempting a conversion are the definitive ways to tell if a given object can be converted to JSON data.
 */
NSMutableDictionary *gpsInfo = [NSMutableDictionary dictionary];
gpsInfo[@"test"] = @(1.0 / 0.0);
[NSJSONSerialization isValidJSONObject:gpsInfo];		// 不合法
```

使用C语言中的宏判断NSNumber

```objc
NSNumber *obj = @(1.0 / 0.0);
isinf(obj.doubleValue);   // YES
isnan(obj.doubleValue);		// NO
```

使用``try catch``，兜住异常

````objc
		@try {
        gpsData = [NSJSONSerialization dataWithJSONObject:gpsInfo 
                   options:NSJSONWritingPrettyPrinted 
                   error:&parseError];
    } @catch (NSException *exception) {

    } @finally {

    }
````



### 2 基于mach-o的无用方法检测，编译参数问题

需要设置编译参数，一般`Debug`是这样设置的，`Release`不是这样设置。

```
DEPLOYMENT_POSTPROCESSING=NO 
STRIP_STYLE=debugging
```

无用方法脚本，不能从`mach-o`查询到工程源码中包含的类和方法，是因为`mach-o`里就没有。

编译参数说明：https://www.jianshu.com/p/0ffbcec6a76e

无用方法脚本：https://github.com/xuezhulian/selectorsunref



### 3 Swift 继承`UIViewController`，初始化方法

需要重写`UIViewController`的2个init方法

```swift
class ProductDetailViewController: UIViewController {
    var productItem : ProductItem;
    
    
    init(item: ProductItem) {
        productItem = item
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
```