using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第一章_进化史
{
    class 排序和过滤
    {
        /// <summary>
        /// C#1使用IComparer对ArrayList进行排序
        /// </summary>
        private class ProductNameComparer01 : IComparer<object>
        {
            public int Compare(object x,object y)
            {
                Product first = (Product)x;
                Product second = (Product)y;
                return first.Name.CompareTo(second.Name);
            }
        }
        void Sort01()
        {
            //获取Product，但是强制类型转换可能报错，如果返回的ArrayList含有不是Product的对象，在转换的时候报错
            //ArrayList productList = Product01.GetSampleProducts();
            //productList.Sort(new ProductNameComparer01());
            //foreach (var product in productList)
            //{
            //    Console.WriteLine(product);
            //}
        }

        /// <summary>
        /// C#2使用IComparer<Product>对List<Product>进行排序
        /// </summary>
        private class ProductNameComparer02 : IComparer<Product>
        {
            public int Compare(Product x, Product y)
            {
                return x.Name.CompareTo(y.Name);
            }
        }
        void Sort02()
        {
            //获取Product，但是强制类型转换可能报错，如果返回的ArrayList含有不是Product的对象，在转换的时候报错
            List<Product> productList = Product.GetSampleProducts();
            productList.Sort(new ProductNameComparer02());//①
            productList.Sort(delegate(Product x, Product y) { return x.Name.CompareTo(y.Name); });//②
            foreach (var product in productList)
            {
                Console.WriteLine(product);
            }
        }
        /// <summary>
        /// C#3使用Lambda表达式对List<Product>进行排序
        /// </summary>
        void Sort03()
        {
            List<Product> productList = Product.GetSampleProducts();
            //①先排序在打印
            productList.Sort((x,y)=> x.Name.CompareTo(y.Name));
            foreach (Product product in productList)
            {
                Console.WriteLine(product);
            }
            //②不用排序直接按名字打印OrderBy拓展方法（允许列表保持未排序状态）
            foreach (Product product in productList.OrderBy(p=>p.Name))
            {
                Console.WriteLine(product);
            }
        }
        //——————————————查询——————————
        ///C# 1.0  测试和打印在一起，不灵活
        void Test01()
        {
            ArrayList products = Product01.GetSampleProducts();
            foreach (Product01 product in products)
            {
                if (product.Price > 10m)
                {
                    Console.WriteLine(product);
                }
            }
        }
        //C# 2.0  测试与打印分开
        void Test02()
        {
            List<Product> products = Product.GetSampleProducts();

            Predicate<Product> test = delegate (Product p) { return p.Price > 10m; };
            List<Product> matches = products.FindAll(test);

            Action<Product> print = Console.WriteLine;
            matches.ForEach(print);

            //简写：
            products.FindAll(delegate (Product p) { return p.Price > 10; }).ForEach(Console.WriteLine);
        }

        //C# 3.0  利用lambada
        void Test03()
        {
            List<Product> products = Product.GetSampleProducts();
            
            foreach (var product in products.Where(p => p.Price > 10))
            {
                Console.WriteLine(product);
            }
            //简写：
            products.FindAll(p => p.Price > 10).ForEach(Console.WriteLine);
        }
    }
}
