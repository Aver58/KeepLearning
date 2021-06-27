using System;
using System.Collections;
using System.Threading;
using System.Threading.Tasks;

namespace TestCoroutine
{
    class TestCoroutine
    {
        //static void Main(string[] args)
        //{
        //    //Console.WriteLine("[Main] coroutine test begin");

        //    //CoroutineManager.Instance.Start(CoroutineTest());
        //    //int framecount = 0;//模拟当前帧数,当前time下，1秒50帧
        //    //while(true)
        //    //{
        //    //    framecount++;
        //    //    Console.WriteLine("[Main] cur framecount:<" + framecount + "> CoroutineManager.Instance.UpdateCoroutine");

        //    //    CoroutineManager.Instance.UpdateCoroutine();

        //    //    //模拟unity的update
        //    //    Thread.Sleep(Time.deltaMilTime);
        //    //    if(framecount >= 35)
        //    //        break;
        //    //}

        //    string tid = Thread.CurrentThread.ManagedThreadId.ToString();
        //    Console.WriteLine($"Main1 tid {tid}");
        //    CalAsync();
        //    Console.WriteLine($"Main after CalAsync");
        //    Console.ReadLine();
        //}

        private static IEnumerator CoroutineTest()
        {
            Console.WriteLine("[CoroutineTest] enter coroutine. begin return waitforseconds:0.5f");
            yield return new WaitForSeconds(0.5f);

            Console.WriteLine("[CoroutineTest] wait for seconds <0.5f> over. begin wait for frame:3");
            yield return new WaitForFrame(3);

            Console.WriteLine("[CoroutineTest] wait for frame <3> over. now exit corutine");
        }

        public static async void CalAsync()
        {
            int result = await Task.Run(Cal);
            Console.WriteLine(result);
        }

        public static int Cal()
        {
            int sum = 0;
            for(int i = 0; i < 999; i++)
            {
                sum = sum + i;
            }
            Console.WriteLine($"sum={sum}");
            return sum;
        }
    }
}
