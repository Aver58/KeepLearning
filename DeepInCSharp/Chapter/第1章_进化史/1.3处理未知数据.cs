using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第一章_进化史
{
    class 处理未知数据
    {
        //C#1 decimal是值类型
        //要表示价格可空的话
        //1、围绕decimal创建一个引用类型包装器
        //2.维护一个单独bool来表示价格是否已知
        //3.使用decimal.MinValue来表示未知价格

        //C#2/C#3  语法糖：decimal？
        //decimal? price;
        //public decimal Price
        //{
        //    get => price;
        //    private set { price = value; }
        //}
        // p.Price == null 


        //C#4 可选参数和默认值
        class Product
        {
            public string Name { get; }
            public decimal? Price { get; }

            public Product(string name, decimal? price = null)//可空参数
            {
                this.Name = name;
                this.Price = price;
            }

            public static List<Product> GetSampleProducts()
            {
                return new List<Product>()
            {
                new Product(name: "West Side Story", price: 9.99m),
                new Product(name: "West Side Story", price: 9.99m),
                new Product(name: "West Side Story", price: 9.99m),
                new Product(name: "West Side Story", price: 9.99m),
            };
            }

            public override string ToString()
            {
                return string.Format("{0}:{1}", Name, Price);
            }
        }
    }
}
