using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第一章_进化史
{
    class 怎样写出酷炫代码
    {
        static string Reverse(string input)
        {
            char[] chars = input.ToCharArray();
            Array.Reverse(chars);
            return new string(chars);
        }
        [STAThread]//Snippy调用内嵌类、相当于using
        //STAThread：Single Thread     Apartment Thread.(单一线程单元线程)
        static void Mains()//要用的时候改成Main
        {
            Console.WriteLine(Reverse("olleH"));

            Console.ReadLine();

        }
    }
}
