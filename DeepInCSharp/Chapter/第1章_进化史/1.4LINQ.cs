using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace DeepInCSharp.第一章_进化史
{
    class LINQ
    {
        //C#1/C#2 过滤集合
        void Test01()
        {
            List<Product> products = Product.GetSampleProducts();
            var filtered = from Product p in products
                           where p.Price > 10
                           select p;
            foreach (var product in filtered)
            {
                Console.WriteLine(product);
            }
        }
        //C#3 连接(joining)、过滤(filtering)、排序(ordering)、投影(Projecting)

        void Test02()
        {
            //找出产品对应的供应商，并且价格大于10的产品
            List<Product> products = Product.GetSampleProducts();
            List<Supplier> suppliers = Supplier.GetSampleSuppliers();
            var filtered = from p in products
                           join s in suppliers on p.SupplierID equals s.SupplierID
                           where p.Price > 10m
                           orderby s.Name, p.Name
                           select new { SupplierName = s.Name, ProductName = p.Name };
            foreach (var v in filtered)
            {
                Console.WriteLine(v.ProductName + v.ProductName);
            }
        }

        //查询xml
        void Test03()
        {
            XDocument doc = XDocument.Load("data.xml");
            var filtered = from p in doc.Descendants("Product")
                           join s in doc.Descendants("Supplier")
                           on (int)p.Attribute("SupplierID")
                           equals (int)s.Attribute("SupplierID")
                           where (decimal)p.Attribute("Price") > 10
                           orderby (string)s.Attribute("Name"),
                                   (string)p.Attribute("Name")
                           select new
                           {
                               SupplierName = (string)s.Attribute("Name"),
                               ProductName = (string)p.Attribute("Name")
                           };
            foreach (var v in filtered)
            {
                Console.WriteLine(v.ProductName + v.ProductName);
            }
        }

        //C#3 对SQL数据库应用查询
        /*
        void Search()
        {
            using (LinqDemoDataContext db = new LinqDemoDataContext())
            {
                var filtered = from p in db.Products
                               join s in db.Suppliers
                                    on p.SupplierID equals s.SupplierID
                               where p.Price > 10
                               orderby s.Name, p.Name
                               select new { SupplierName = s.Name,ProductName = p.Name};
                foreach (var v in filtered)
                {
                    Console.WriteLine("Supplier = {0};Product = {1}",v.SupplierName,v.ProductName);
                }
            }
        }
        */
    }
}
