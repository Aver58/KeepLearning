using System;
using System.Reflection;
class SimpleReflection
{
    public static void Test()
    {
        var person = new Person("LiMing", 18);
        var student = new Student("LiMing", 18);
        var people = new Person[] { person, student };
        foreach(var item in people)
        {
            var t = item.GetType();
            //获取类型名称
            Console.WriteLine("类型名称:" + t.Name);
            //命名空间
            Console.WriteLine("\t命名空间:" + t.Namespace);
            //类型的 程序集
            Console.WriteLine("\t程序集：" + t.Assembly.FullName);
            //获取字段信息
            var publicFieldInfos = t.GetFields();
            foreach(var fieldInfo in publicFieldInfos)
            {
                Console.WriteLine("\t公有字段：" + fieldInfo.Name);
            }
            //获取所有字段信息
            var privateFieldInfos = t.GetFields(BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Public);
            foreach(var fieldInfo in privateFieldInfos)
            {
                Console.WriteLine("\t私有字段：" + fieldInfo.Name);
            }
            //获取属性信息，忽略继承的属性
            var propertyInfos = t.GetProperties(BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Public | BindingFlags.DeclaredOnly);
            foreach(var propertyInfo in propertyInfos)
            {
                Console.WriteLine("\t公有属性：" + propertyInfo.Name);
            }

            // 查看类的成员信息
            var memberInfos = t.GetMembers();
            foreach(var memberInfo in memberInfos)
            {
                Console.WriteLine("\t成员信息：" + memberInfo.Name);
            }

            // 查看类的构造函数
            var constructorInfos = t.GetConstructors();
            foreach(ConstructorInfo constructorInfo in constructorInfos)
            {
                Console.WriteLine("\t构造方法");
                //获取每个构造函数的所有参数
                var ps = constructorInfo.GetParameters();
                foreach(var pi in ps)
                {
                    Console.WriteLine("\t\t参数类型:{0},参数名称:{1}", pi.ParameterType.ToString(), pi.Name);
                }
            }

        }

        GetTypesFromAssembly(@"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.6.1\System.dll");
    }

    /// <summary>
    /// 获取程序集的所有类型
    /// </summary>
    /// <param name="assemblyName">示例C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.6.1\System.dll</param>
    static void GetTypesFromAssembly(string assemblyName)
    {
        Assembly assembly = Assembly.LoadFrom(assemblyName);
        Type[] types = assembly.GetTypes();
        foreach(var item in types)
        {
            Console.WriteLine(item.Name);
        }
    }
    static decimal GetMethodFromDll()
    {
        Assembly assembly = Assembly.LoadFrom(@"D:\csharp\反射\ReflectionTest\Calculator\bin\Debug\Calculator.dll");
        Type t = assembly.GetType("Calculator.Calc");
        Console.WriteLine(t.Name);
        object[] pramList = new object[2] { 10m, 20m };
        object obj = Activator.CreateInstance(t, pramList);
        MethodInfo method = t.GetMethod("add");
        return (decimal)method.Invoke(obj, null);
    }
}

public class Person
{
    public int IDNumber;
    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }
    public string Name { get; set; }
    public int Age { get; set; }
    public string Gender { get; set; }
    public void Eat()
    {
        Console.WriteLine("吃饭");
    }
    private void Sleep()
    {
        Console.WriteLine("睡觉");
    }
}

public class Student : Person
{
    public Student(string name, int age) : base(name, age)
    {
    }
    public string Major { get; set; }
    public DateTime EnrollDate { get; set; }
    public void AttendClass()
    {
        Console.WriteLine("去上课");
    }
}
