using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第10章__拓展方法
{
    class Extension
    {
        static void Mains()//要用的时候改成Main
        {
            //WebRequest request = WebRequest.Create(new Uri("http://manning.com"));
            //WebResponse response = request.GetResponse();
            //using (Stream responseStream = response.GetResponseStream())
            //using (FileStream output = File.Create("response.dat"))
            //{
            //    //StreamUtil.Copy(responseStream, output);
            //    Console.WriteLine(responseStream);

            //    responseStream.CopyTo(output);
            //}

            var collection = Enumerable.Range(0, 10).Reverse().Where(x=>x%2 == 0);
            foreach (var item in collection)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }
    }
}
