using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    /// <summary>
    /// 一个字符串，返回该字符串中最长的连续不重复子串（字符串只包含小写字母）
    /// </summary>
    class GetLongestSubStringClass
    {
        static bool IsDuplicate(string source,char target)
        {

            for (int i = 0; i < source.Length - 1; i++)
            {
                if (source[i] == target)
                {
                    return true;
                }
            }
            return false;
        }
        //n平方算法
        public static string GetLongestSubDiffStringNN(string s)
        {
            if (string.IsNullOrEmpty(s)||s==" ")
            {
                Console.WriteLine("Empty string!!");
                return null;
            }

            int maxLength = 0, tempLength = 0;
            string tempStr = "", maxStr = "";
            var chars = s.ToCharArray();

            for (int i = 0; i <= chars.Length - 1; i++)
            {
                //if (IsDuplicate(tempStr, chars[i])
                if (tempStr.Contains(chars[i]))
                    {
                    tempLength = 1;
                    tempStr = s[i].ToString();
                }
                else
                {
                    tempLength++;
                    tempStr += s[i];
                    maxStr = tempLength > maxLength ? tempStr : maxStr;
                    maxLength = tempLength > maxLength ? tempLength : maxLength;
                }
            }
            return maxStr;
        }

        public static string GetLongestSubDiffStringN(string s)
        {
            if (string.IsNullOrEmpty(s) || s == " ")
            {
                Console.WriteLine("Empty string!!");
                return null;
            }

            int maxLength = 0, tempLength = 0;
            string tempStr = "", maxStr = "";
            //用字典存储已存在字符，省去n次的遍历
            Dictionary<char, int> haveCharDic = new Dictionary<char, int>();
            var chars = s.ToCharArray();

            for (int i = 0; i <= chars.Length - 1; i++)
            {
                if (haveCharDic.ContainsKey(s[i]))
                {
                    tempLength = 1;
                    tempStr = s[i].ToString();
                    // 初始化字典
                    haveCharDic = new Dictionary<char, int>();
                    haveCharDic[s[i]] = 1;
                }
                else
                {
                    tempLength++;
                    tempStr += s[i];
                    haveCharDic[s[i]] = 1;
                    maxStr = tempLength > maxLength ? tempStr : maxStr;
                    maxLength = tempLength > maxLength ? tempLength : maxLength;
                }
            }
            return maxStr;
        }
    }

    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        var str = GetLongestSubStringClass.GetLongestSubDiffStringNN("ABCDABGDFKJGYVVJBHBVHTHCGCGUJ");
    //        var str2 = GetLongestSubStringClass.GetLongestSubDiffStringN("ABCDABGDFKJGYVVJBHBVHTHCGCGUJ");
    //        Console.WriteLine(str);
    //        Console.WriteLine(str2);
    //        Console.ReadLine();
    //    }
    //}
}
