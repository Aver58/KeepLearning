//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

//namespace DeepInCSharp.第一章_进化史
//{
//    class 轻松编写异步代码
//    {
//        //C#5特性：异步函数：中断代码执行
        
//        class directory
//        {
//            public static async Task<Product> LookupProductAsync(string id)
//            {
//                return new Product(id,10);
//            }
//        }

//        class warehouse
//        {
//            public static async Task<int> LookupStockLevelAsync(string id)
//            {
//                //查询操作blahblah
//                return 0;
//            }
//        }

//        private async void CheckProduct(object sender, EventArgs e)
//        {
//            try
//            {
//                string id = "";
//                Task<Product> productLookup = directory.LookupProductAsync(id);
//                Task<int> stockLookup = warehouse.LookupStockLevelAsync(id);
//                Product product = await productLookup;//等待获取产品信息
//                if (product == null) return;

//                int stock = await stockLookup;  //等待获取库存信息
//            }
//            catch (Exception)
//            {

//                throw;
//            }
//        }
//    }
//}
