1. 请简述值类型与引用类型的区别。
> 值类型传递的是值本身，引用类型传递的是地址。
1. C#中所有引用类型的基类是什么？
> object
1. 请简述ArrayList和List<int>之间的主要区别。
> LIST是接口类，ArrayList类实现了这个接口，可以这样用：List a=new ArrayList();
1. 请描述interface和抽象类之间的不同。
> todo 写一篇？
1. 请简述sealed关键字用在类声明时与函数声明时的作用。
> 作为类别的时候 不能有子类 作为函数的修饰符的时候 在子类里不能重写函数
1. 请简述private，public，protected，internal的区别。
>- private：私有成员，在类的内部才可以访问。
>- public：公共成员，完全公开，没有访问限制。
>- protected：保护成员，该类内部和继承中可以访问。
>- internal：当前程序集内可以访问。

1. 请简述反射的实现原理。
>- 在程序运行时，动态获取 程序集， 类型（class，interface）和类型的成员信息（方法，字段，属性等）。
>- 在程序运行时，动态创建 类型实例，以及调用和方法 动态创建出来的 类型实例的成员。

1. 请简述.Net与Mono之间的关系。
> mono是.net的一个工具，.net只能在windows平台下跑，mono可以跨平台

1. Unity3D是否支持写成多线程程序？如果支持的话要注意什么？
>- 支持：如果同时你要处理很多事情或者与Unity的对象互动小可以用thread,否则使用coroutine。
>- 注意：C#中有lock这个关键字,以确保只有一个线程可以在特定时间内访问特定的对象

1. Unity3D中的协程（coroutine）和C#线程之间的区别是什么？
>- Unity3d没有多线程的概念，不过unity也给我们提供了StartCoroutine（协同程序）和LoadLevelAsync（异步加载关卡）后台加载场景的方法。 
>- StartCoroutine为什么叫协同程序呢，所谓协同，就是当你在StartCoroutine的函数体里处理一段代码时，利用yield语句等待执行结果，这期间不影响主程序的继续执行，可以协同工作。