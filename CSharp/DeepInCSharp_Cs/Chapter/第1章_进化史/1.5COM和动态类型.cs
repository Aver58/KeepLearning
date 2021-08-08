using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第一章_进化史
{
    class COM和动态类型
    {
        //C#4特有的
        //C#4简化COM互操作  将数据保存到新的电子表格
        void COMTest()
        {
            //var app = new Application { Visible = false };//Application是啥
            //Workbook workbook = app.workbooks.add();
            //worksheet worksheet = app.ActiveSheet;
            //int row = 1;
            //foreach (var product in Product.GetSampleProducts())
            //{
            //    worksheet.Cell[row, 1].value = product.Name;
            //    worksheet.Cell[row, 2].value = product.Price;
            //}
            //workbook.SaveAs(FileName: "demo.xls");//使用命名实参调用SaveAs
            //app.Application.Quit();
        }

        //与动态语言交互  dynamic
        void Test()
        {
            //ScriptEngine engine = python.CreateEngine();
            //scriptScope scope = engine.ExecuteFile("FindProducts.py");
            //dynamic products = scope.GetVariable("products");
            //foreach (dynamic product in Products)
            //{

            //}
        }
    }
}
