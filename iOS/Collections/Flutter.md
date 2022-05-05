### [Hummer 引擎优化系列 - 大批干货来袭预警](https://mp.weixin.qq.com/s/esYrzI1N_AsZPjJXZxnSdQ)

Hummer 是 UC 内核团队定制的 Flutter 引擎，它基于官方 Flutter 引擎进行优化增强。经过近两年的持续优化和增强，Hummer 在各方的表现都足够亮眼，且经过了巨量的验证，接下来 UC 团队将会讲这些优化经验回馈于社区，可谓是干货满满，主要集中在:

- 性能优化
- 包体积优化
- 内存稳定性
- Dart 语言层优化
- 业务层功能增强



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