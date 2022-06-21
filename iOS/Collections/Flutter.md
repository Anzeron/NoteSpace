### [Hummer 引擎优化系列 - 大批干货来袭预警](https://mp.weixin.qq.com/s/esYrzI1N_AsZPjJXZxnSdQ)

Hummer 是 UC 内核团队定制的 Flutter 引擎，它基于官方 Flutter 引擎进行优化增强。经过近两年的持续优化和增强，Hummer 在各方的表现都足够亮眼，且经过了巨量的验证，接下来 UC 团队将会讲这些优化经验回馈于社区，可谓是干货满满，主要集中在:

- 性能优化
- 包体积优化
- 内存稳定性
- Dart 语言层优化
- 业务层功能增强

### [【Hummer Flutter引擎】让Flutter绽放得更美 - 包体积优化之道](https://mp.weixin.qq.com/s/OnAnOAX1K5TyHbuUjV3LEg)

[@极速男孩](https://github.com/ztlyyznf001): Flutter 的包体积一直是个让开发者头疼的问题。 本文主要介绍了 Hummer 引擎是如何通过引擎的优化和精简，分包动态化技术和资源的优化来完成对包体积缩减。并且介绍了监控和动态化平台的落地。

### [Flutter PlatformView 优化](https://mp.weixin.qq.com/s/gJXk56yJ5oJREHCUbsdhXg)

C 的 U4 内核团队针对 Flutter 上的 PlatformView 做了深入的研究，并且做了一下优化 PR（部分合入到官方中），主要是针对 Android 的场景，目前官方提供的 Virtual displays 和 Hybrid composition 都存在一些问题，Virtual displays 存在功能性问题，Hybrid composition 存在因为线程合并带来的性能问题，以及死锁风险，且在 Android Q 以下因为内存拷贝导致性能变差。在之前的 Hummer 引擎中实现了挖洞模式，并且通过移植 Roger 大神在 U4 浏览器内核中实现的 Embed Surface 方案，来进一步优化。并且 Embed Surface 方案被合入到主线，后续会逐渐弃用 Hybrid composition。因此可以期待最新的 release 版本。

最终得到的结论：

- 「挖洞模式」的性能仍然是最好的。在挖洞模式能满足的场景下，请考虑优先使用挖洞；
- Embed Surface 除了仅支持 Android 6.0 及以上外，没有明显短板，其帧率在大多数场景下可以与挖洞模式持平；
- 从测试数据看，不合并线程的 HybridComposition 的帧率波动比较大，并不比 Embed Surface 有优势。另外，因为不能完全避免 Android Q 以下的内存拷贝，同时还需要处理部分场景下的同步问题，所以我们不会继续优化该方案。

### [Dutter | 钉钉 Flutter 跨四端方案设计与技术实践](https://mp.weixin.qq.com/s/JyfwrfsWplHhkColYLhBpg)

[@老峰](https://github.com/gesantung)：Dutter 即 DingTalk Flutter，是钉钉内基于 Flutter 构建的跨四端研发框架，本文主要包含以下内容：

- 整体架构： Dutter Runtime、Dutter Dev Kit、Dutter OPS Kit；
- 数据通信包括：Channel、Dutter FFI；
- 消息总线；
- 模块化；
- 容器化；
- 组件库：dingui_flutter 、dingtalk_uikit；
- 最佳实践以及部分 FlutterEngine 层面的问题定位等。

### [Flutter 深入探索混合开发的技术演进](https://mp.weixin.qq.com/s/JjlCyCOC4gL7hx3UNs7ONQ)

本文梳理了 Flutter 中 PlatformView 的演进过程，也就是从直接通过 channel 打开一个 WebviewController 到 Virtual Displays 到 Flutter Hybrid Composition 的过程，文中通过各种例子说明原理以及也指明了优缺点，在使用 Flutter 的同学建议一看。同时上周推荐的 UC 团队做的进一步优化进行是下一步演进方向，也可以一并看看。

参考链接： [U4 内核技术 - Flutter PlatformView 优化](https://mp.weixin.qq.com/s/gJXk56yJ5oJREHCUbsdhXg)

### [Flutter 状态管理框架 Provider 和 Get 分析](https://mp.weixin.qq.com/s/iLSjr-HE4VC1kTdjI2bFNQ)

[@极速男孩](https://github.com/ztlyyznf001)：Flutter 作为一个声明式的 UI 框架状态管理是一个让人头疼的问题，没有状态管理会导致难以复用/单元测试，跨页面无法传递数据，setState 方法会过度刷新的问题。本文主要介绍了 Get 与 Provider 的状态管理的原理，并且如何利用他们去实现 MVP 模式，并且对比了两者的优缺点。

### [“Stop” using state management libraries](https://medium.com/flutter-community/stop-using-state-management-libraries-48a81ed7979d)

[@CrazyCoderShi](https://github.com/CrazyCoderShi): 在 Flutter 项目中状态管理是必须要解决的问题，行业内也有各种解决方案，例如: GetX, Provider, MobX, BLoc 等，但在其下更应该思考的是是否有必要？本文标题党一把，从其需求根本上讨论使用的必要性，非常推荐小白细读.

### [Flutter 新一代图形渲染器 Impeller](https://mp.weixin.qq.com/s/PLvlSt3tlX6AjufDm0XVMA)

Flutter在2022年的Roadmap中提出需要重新考虑着色器的使用方式，计划重写图像渲染后端。最近该渲染后端 Impeller（叶轮）初见端倪，[本文](https://mp.weixin.qq.com/s/PLvlSt3tlX6AjufDm0XVMA)就从 Flutter 图形渲染优化历史讲起，一步步带你了解 Flutter 下图形渲染的优化，以及最新开发中的 Impeller ，详细带你了解 Impeller 的方方面面

### [Flutter 比 React Native 更好吗？](https://mp.weixin.qq.com/s/DozzpgKxvXtgBG1-tYjboQ)

本文作者是一家软件开发公司的创始人兼 CTO，同时也是 React Native 的核心成员。在这篇文章里，作者试着尽可能公平地从人力成本，开发者体验，性能，体验，Web 支持，第三方生态，动态更新，以及使用它们的公司等多方面，去讨论 Flutter 和 React Native 的优劣，让大家在项目技术选型时多一点指导权衡思考的素材。

### [Flutter在携程复杂业务的高性能之旅](https://mp.weixin.qq.com/s/QgPXNpdU2mlAb6tlcsm_eQ)

Flutter 在渲染性能上一直都是其宣传的亮点，然而即使这样在业务开发中仍然有较多需要注意的地方，本文由携程团队给大家带来的 Flutter 下复杂场景的性能优化，涉及方方面面，干货满满，所有优化项所见所得:

- UI 线程优化
  - 拆分VieModel降低刷新几率
  - Provider监听数据推荐使用Selector
  - 减少在build中做耗时操作，放到Isolate去执行
  - 缓存高层级组件
  - 控制刷新范围、频次
  - setState 刷新颗粒度在最低层
  - const 修饰避免频繁构造
- GPU 线程优化
  - 使用RepaintBinary隔离 提别是轮播广告、动画
  - 减少ClipPath的使用,简单圆角采用BoxDecoration实现
  - 避免Opacity,可以通过切图实现。有动画效果的建议用AnimatedOpacity
  - 避免使用带换行符的长文本
- 图片渲染性能和内存开销治理
  - 图片预加载
  - 资源优化
  - 图片内存优化
- 长列表滑动性能优化
  - ListView Item 复用
  - 首页预加载
  - 分页预加载
  - 取消在途网络请求

小编强烈推荐 👍 ，同时再次推荐携程团队的[另一个干货: Flutter控件CustomScrollView原理解析及应用实践](https://mp.weixin.qq.com/s/dF5Id3w_To4aXeXDbUnUjQ)给同学们搭配学习

### [Flutter 代码生成 source_gen 使用与原理分析](https://mp.weixin.qq.com/s/lrEzYdbafrqfDVFQl2ebRQ)

众所周知，你应该多少会用过 json_serializable 吧，那么就一定知道基本的原理是通过解析声明文件，从而生成相关 json 序列化和反序列化代码。那么当你从事过较多的开发之后，一定会遇到很多重复的代码复制粘贴，例如：路由的编写，或者 channel 的生成，架构代码生成，ImageAsset 代码生成等等。那么你应该会自然地想到，我也可以像 json_serializable 和 pigeon 去做一些提高效率的工具，那这时候可以看下 source_gen，这个库进行了一些封装，让你更方便的定制代码生成的逻辑。

### [Flutter 滑动体验对齐原生 - 滑动曲线篇](https://mp.weixin.qq.com/s/aqXdYYEArhEj6ikqg2oX9g)

本文介绍了在 Flutter 的滑动手感拉齐 Native 方向上做出的努力。主要思路分为两步：解决 fling 动画在一次滑动中反复重启；选择更合适的衰减公式。同时介绍了调整滑动曲线的一些常用思路：降低初速度给曲线减速；通过对初始速度叠加衰减值，运用二次函数，在快速滑动时衰减慢，慢速滑动时衰减快。

### [Flutter 音视频开发新思路](https://mp.weixin.qq.com/s/ZpHfkz8CQmPhKY4--WYTWw)

因为众多优秀的设计而在跨端方案中脱颖而出，成为目前跨端开发的主流选型。常规的业务功能和逻辑模块通过应用 Flutter 可以较好的实现双端代码的一致性。但是对于某些细分领域，比如音视频，对资源的使用和计算的性能高度敏感，Flutter 能做的可能就只能是偏向于纯展示，更多的逻辑都下沉在 Native 实现。虽然能满足需求，但丢失了 Flutter 跨端的优势。闲鱼在这个方向探索了一个新的思路。将音视频处理细化为一个个处理单元，然后在 Flutter 侧将这些处理单元组织成 pipeline 来实现业务逻辑，在保证可用性的基础上最大限度的提升了跨端代码的占比。虽然 Flutter 究竟是否适合音视频场景，业界也是有一定争议的。但这个方案有一定新颖性，也是值得研究学习一下的。

### [Flutter图片库重磅开源](https://mp.weixin.qq.com/s/WnpDbDvEVNMj_96ulnuWkQ)

[@CrazyCoderShi](https://github.com/CrazyCoderShi): 去年，闲鱼技术团队新一代图片库 PowerImage 在经过一系列灰度、问题修复、代码调优后，已全量稳定应用于闲鱼。相对于上一代 IFImage，PowerImage 经过进一步的演进，适应了更多的业务场景与最新的 flutter 特性，解决了一系列痛点.