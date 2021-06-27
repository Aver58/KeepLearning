//①sealed class 密封类，禁止继承
//public sealed class SealedClass { }
//public sealed class SealedClassA : SealedClass { } // error 无法从密封类型继承

//②sealed method 密封方法，防止子类重写特定的方法或属性
using System;
public class A
{
    protected virtual void M() { Console.WriteLine("A.M()"); }
    protected virtual void M1() { Console.WriteLine("A.M1()"); }
}

public class B : A
{
    protected sealed override void M() { Console.WriteLine("B.M()"); }
    protected override void M1() { Console.WriteLine("B.M1()"); }
}

public sealed class C : B
{
    // B.M是密封的，无法重写
    //protected override void M() { Console.WriteLine("C.M()"); } // error

    protected override void M1() { Console.WriteLine("C.M1()"); }
}