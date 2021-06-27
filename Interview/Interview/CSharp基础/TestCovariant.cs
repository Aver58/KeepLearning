using System;

// 协变
class TestCovariant
{
    static object GetObject() { return null; }
    static void SetObject(object obj) { }

    static string GetString() { return ""; }
    static void SetString(string str) { }

    //泛型委托：
    public delegate T MyFuncA<T>();//不支持逆变与协变
    public delegate T MyFuncB<out T>();//支持协变
    //泛型接口
    public interface IFlyA<T> { }//不支持逆变与协变
    public interface IFlyB<out T> { }//支持协变

    static void Test()
    {
        //msdn上说,它们返回与委托类型指定的派生类型相比，派生程度更大的类型（协变）
        //也就是说,原本是要返回string类型的,现在转换成了派生程度更大的object类型
        Func<object> del = GetString;    //协变
        //msdn上说, 接受相比之下，派生程度更小的类型的参数（逆变）
        //也就是说, 原本是需要接受object类型,现在接受了更小的string类型的参数
        Action<string> del2 = SetObject;    //逆变


        MyFuncA<object> funcAObject = null;
        MyFuncA<string> funcAString = null;
        MyFuncB<object> funcBObject = null;
        MyFuncB<string> funcBString = null;
        MyFuncB<int> funcBInt = null;

        //funcAObject = funcAString;//编译失败，MyFuncA不支持逆变与协变
        //funcBObject = funcBInt;//编译失败，值类型不参与协变或逆变
        funcBObject = funcBString;//变了，协变



        IFlyA<object> flyAObject = null;
        IFlyA<string> flyAString = null;
        IFlyB<object> flyBObject = null;
        IFlyB<string> flyBString = null;
        IFlyB<int> flyBInt = null;

        //flyAObject = flyAString;//编译失败，IFlyA不支持逆变与协变
        //flyBObject = flyBInt;//编译失败，值类型不参与协变或逆变
        flyBObject = flyBString;//变了，协变
    }
}


