using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructure
{
    class Search<T>
    {
        //一. 顺序查找
        //二.二分查找（前提：顺序排放，list）

        public int BinarySearch(int[] table , int item)
        {
            int left = 1;
            int right = table.Length;
            int mid;
            while (left<right)
            {
                mid = (left + right) / 2;
                if (table[mid] < item)
                {
                    left = mid;
                }
                else if(table[mid] < item)
                {
                    right = mid;
                }
                else
                {
                    return mid;
                }
            }
            return -1;
        }
    }
}
