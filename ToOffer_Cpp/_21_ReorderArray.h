// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。
#pragma once
class _21_ReorderArray
{
	bool IsEven(unsigned int value) {
		return value & 1 == 0;
	}
    
// ====================方法一:// 双指针，从后面找到一个奇数，从前面找到一个偶数，交换【O(n)】====================
	void ReorderOddEven_1(int* pData, unsigned int length)
	{
		if (pData == nullptr || length == 0)
			return;

		int* pBegin = pData;
		int* pEnd = pData + length - 1;
        while (pBegin < pEnd)
        {
            // 向后移动pBegin，直到它指向偶数
            while (pBegin < pEnd && (*pBegin & 0x1) != 0)
                pBegin++;

            // 向前移动pEnd，直到它指向奇数
            while (pBegin < pEnd && (*pEnd & 0x1) == 0)
                pEnd--;

            if (pBegin < pEnd)
            {
                int temp = *pBegin;
                *pBegin = *pEnd;
                *pEnd = temp;
            }
        }
	}
    // ====================方法二: 抽象出方法，解耦算法和业务====================
    //void ReorderOddEven_2(int* pData, unsigned int length)
    //{
    //    Reorder(pData, length, isEven);
    //}

    //void Reorder(int* pData, unsigned int length, bool(*func)(int))
    //{
    //    if (pData == nullptr || length == 0)
    //        return;

    //    int* pBegin = pData;
    //    int* pEnd = pData + length - 1;

    //    while (pBegin < pEnd)
    //    {
    //        // 向后移动pBegin
    //        while (pBegin < pEnd && !func(*pBegin))
    //            pBegin++;

    //        // 向前移动pEnd
    //        while (pBegin < pEnd && func(*pEnd))
    //            pEnd--;

    //        if (pBegin < pEnd)
    //        {
    //            int temp = *pBegin;
    //            *pBegin = *pEnd;
    //            *pEnd = temp;
    //        }
    //    }
    //}
    //bool isEven(int n)
    //{
    //    return (n & 1) == 0;
    //}

};