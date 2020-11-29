#region Copyright © 2020 Aver. All rights reserved.
/*
=====================================================
 AverFrameWork v1.0
 Filename:    AbstractClassDemo.cs
 Author:      Zeng Zhiwei
 Time:        2020\11\29 星期日 15:35:33
=====================================================
*/
#endregion

public abstract class AbstractClass
{
    public virtual void virtualMethod() { }
    public abstract void method();
}

public abstract class AbstractChildClass: AbstractClass
{
    //public abstract void method();
}