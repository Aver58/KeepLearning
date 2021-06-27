using System;

//事件参数
public class My_EventArgs : EventArgs
{
    private string _args = string.Empty;
    public My_EventArgs(string args)
    {
        _args = args;
    }
    public string Args
    {
        get { return _args; }
    }
}

//事件发行者
public class SourceClass
{
    public double Width { get; set; }
    public double Height { get; set; }

    My_EventArgs Evargs;
    public SourceClass(string args)
    {
        Evargs = new My_EventArgs(args);
    }
    //定义委托
    public delegate void EventHandler(object sender, My_EventArgs args);

    #region 使用委托方式声明
    public EventHandler Clicked;
    public void ClickedAsync()
    {
        if(Clicked != null)
        {
            Clicked(this, Evargs);
        }
    }
    #endregion
    #region 使用事件方式声明
    public event EventHandler Click;
    public void ClickAsync()
    {
        if(Click != null)
        {
            Click(this, Evargs);
        }
    }
    #endregion
}
struct stu2
{
    int k;
    short t;
};

//事件订阅者
public class Del
{
    public delegate void Print(string str);

    static void delegatemethod(string str)
    {
        Console.WriteLine(str);
    }

    public static void Main()
    {
        #region 委托
        //1.普通委托
        var print1 = new Print(delegatemethod);
        print1("这是普通方式创建的委托");
        //2.匿名委托
        Print print2 = delegate (string str) {
            Console.WriteLine(str);
        };
        print2("这是匿名方式创建的委托");
        //3.lambda委托
        Print print3 = (string str) => {
            Console.WriteLine(str);
        };
        print3("这是lambda方式创建的委托");
        #endregion

        #region 事件
        SourceClass source = new SourceClass("我的事件被触发");
        source.Width = 5.0;
        source.Height = 3.0;
        //一、委托方式允许source.Clicked(source, new My_EventArgs("我使用委托方式调用的Args"));调用
        source.Clicked = new SourceClass.EventHandler(source_RightClick);
        source.Clicked += new SourceClass.EventHandler(source_LeftClick);
        source.ClickedAsync();
        source.Clicked(source, new My_EventArgs("我使用委托方式调用的Args"));
        //二、很明显用户希望通过使用source.ClickedAsync();去调用函数，而非直接使用上行代码去调用，所以在这里需要使用Event关键字进行申明
        //注1.事件方式不允许source.Clicked(source, new My_EventArgs("我使用委托方式调用的Args"));直接调用
        //注2.事件不允许 source.Click = new SourceClass.EventHandler(source_LeftClick);直接赋值
        source.Click += new SourceClass.EventHandler(source_LeftClick);
        source.ClickAsync();
        //注销事件和注册事件
        source.Click -= new SourceClass.EventHandler(source_LeftClick);
        source.Click += new SourceClass.EventHandler(source_RightClick);
        source.ClickAsync();
        Console.ReadLine();
        #endregion
    }
    //事件处理方法1
    static void source_LeftClick(object sender, My_EventArgs args)
    {
        SourceClass source = sender as SourceClass;
        Console.WriteLine("目标宽度:" + source.Width + "，目标高度:" + source.Height);
        Console.WriteLine("目标对象参数:" + args.Args);

    }

    //事件处理方法2
    static void source_RightClick(object sender, My_EventArgs args)
    {
        SourceClass source = sender as SourceClass;
        Console.WriteLine("目标面积:" + source.Width * source.Height);
    }
}
