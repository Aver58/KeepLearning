using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第一章_进化史
{
    //C# 1.0:  只读属性、弱类型集合   
    class Product01
    {
        string name;
        public string Name { get { return name; } }

        decimal price;
        public decimal Price { get { return price; } }

        public Product01(string name, decimal price)
        {
            this.name = name;
            this.price = price;
        }

        public static ArrayList GetSampleProducts()
        {
            ArrayList list = new ArrayList();//要装箱和拆箱
            list.Add(new Product01("West Side Story", 9.99m));
            list.Add(new Product01("West Side ", 10.99m));
            list.Add(new Product01("West Side Story", 11.99m));
            list.Add(new Product01("West Story", 12.99m));
            return list;
        }

        public override string ToString()
        {
            return string.Format("{0}:{1}", name, price);
        }
    }

    //C# 2.0:  新增泛型、强类型集合、私有属性赋值方法set   
    class Product02
    {
        string name;
        public string Name { get { return name; } private set { name = value; } }

        decimal price;
        public decimal Price { get { return price; } private set { price = value; } }

        public Product02(string name, decimal price)
        {
            this.name = name;
            this.price = price;
        }

        public static List<Product02> GetSampleProducts()
        {
            List<Product02> list = new List<Product02>();
            list.Add(new Product02("West Side Story", 9.99m));
            list.Add(new Product02("West Side ", 10.99m));
            list.Add(new Product02("West Side Story", 11.99m));
            list.Add(new Product02("West Story", 12.99m));
            return list;
        }

        public override string ToString()
        {
            return string.Format("{0}:{1}", name, price);
        }
    }

    //C# 3.0:  具有自动实现的属性,私有构造函数
    class Product03
    {
        public string Name { get; private set; }
        public decimal Price { get; private set; }

        private Product03()
        {
        }

        public Product03(string name, decimal price)
        {
            Name = name;
            Price = price;
        }

        public static List<Product03> GetSampleProducts()
        {
            return new List<Product03>()
                {
                    new Product03 {Name = "West Side Story", Price = 9.99m},
                    new Product03 {Name = "West Side Story", Price = 9.99m},
                    new Product03 {Name = "West Side Story", Price = 9.99m},
                    new Product03 {Name = "West Side Story",Price = 9.99m }
                };

        }

        public override string ToString()
        {
            return string.Format("{0}:{1}", Name, Price);
        }
    }


    //C# 4.0:  命名实参，让变量不能私有改变
    class Product04
    {
        private readonly string name;//readonly移除易变性    
        public string Name { get { return name; } }

        private readonly decimal price;
        public decimal Price { get { return price; } }

        public Product04(string name, decimal price)
        {
            this.name = name;
            this.price = price;
        }

        public static List<Product04> GetSampleProducts()
        {
            return new List<Product04>()
                {
                    new Product04(name: "West Side Story", price: 9.99m),
                    new Product04(name: "West Side Story", price: 9.99m),
                    new Product04(name: "West Side Story", price: 9.99m),
                    new Product04(name: "West Side Story", price: 9.99m),
                };

        }

        public override string ToString()
        {
            return string.Format("{0}:{1}", Name, Price);
        }
    }

    //终版Product
    class Product
    {
        private readonly string name;//readonly移除易变性    
        public string Name { get { return name; } }

        private readonly decimal price;
        public decimal Price { get { return price; } }
        public int SupplierID { get; set; } //供货商id
        public Product(string name, decimal price)
        {
            this.name = name;
            this.price = price;
        }

        public static List<Product> GetSampleProducts()
        {
            return new List<Product>()
            {
                new Product(name: "West Side Story", price: 9.99m),
                new Product(name: "West Side Story", price: 11m),
                new Product(name: "West Side Story", price: 9.99m),
                new Product(name: "West Side Story", price: 9.99m),
            };
        }

        public override string ToString()
        {
            return string.Format("{0}:{1}", Name, Price);
        }
    }

    public class Supplier
    {
        public string Name { get; set; }

        public int SupplierID { get; set; }

        public static List<Supplier> GetSampleSuppliers()
        {
            return new List<Supplier>();
        }
    }
}
