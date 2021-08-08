using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace DeepInCSharp.第10章__拓展方法
{
    public static class StreamUtil
    {
        const int BufferSize = 8192;
        public static void Copy(Stream input,Stream output)
        {
            byte[] buffer = new byte[BufferSize];
            int read;
            while ((read = input.Read(buffer,0,buffer.Length))>0)
            {
                output.Write(buffer,0,read);
            }
        }
        public static void CopyTo(this Stream input, Stream output)
        {
            byte[] buffer = new byte[BufferSize];
            int read;
            while ((read = input.Read(buffer, 0, buffer.Length)) > 0)
            {
                output.Write(buffer, 0, read);
            }
        }
        public static void isNull(this object o) { }

        public static IEnumerable<T> Where<T>(this IEnumerable<T> collection, Func<T,bool> predicate)
        {
            if (collection == null || predicate == null)
            {
                throw new ArgumentException();
            }
            foreach (var item in collection)
            {
                if (predicate(item))
                {
                    yield return item;
                }
            }
        }
    }
}
