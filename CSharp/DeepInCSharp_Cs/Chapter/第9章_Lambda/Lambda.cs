using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第9章_Lambda
{
    class Lambda
    {
        class Film
        {
            public string Name { get; set; }
            public int Year { get; set; }
        }
        static void Mains()//要用的时候改成Main
        {
            //1.
            Func<string, int> returnLength;
            returnLength = (string text) => { return text.Length; };
            Console.WriteLine(returnLength("111"));
            //2.
            Func<string, int> returnLength2;
            returnLength2 =  text => text.Length;
            Console.WriteLine(returnLength2("1111"));
            //3.
            var films = new List<Film> { new Film { Name = "111", Year = 123 }, new Film { Name = "222", Year = 223 } };
            Action<Film> print = film  => Console.WriteLine("Name = {0} Year = {1}",film.Name,film.Year);
            //films.FindAll(film => film.Year < 150).ForEach(print);
            films.Sort((f1, f2) => f1.Name.CompareTo(f2.Name));
            films.ForEach(print);

            Console.ReadLine();
        }
    }
}
