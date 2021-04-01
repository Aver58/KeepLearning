// ������21����������˳��ʹ����λ��ż��ǰ��
// ��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
// ����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
#pragma once
class _21_ReorderArray
{
	bool IsEven(unsigned int value) {
		return value & 1 == 0;
	}
    
// ====================����һ:// ˫ָ�룬�Ӻ����ҵ�һ����������ǰ���ҵ�һ��ż����������O(n)��====================
	void ReorderOddEven_1(int* pData, unsigned int length)
	{
		if (pData == nullptr || length == 0)
			return;

		int* pBegin = pData;
		int* pEnd = pData + length - 1;
        while (pBegin < pEnd)
        {
            // ����ƶ�pBegin��ֱ����ָ��ż��
            while (pBegin < pEnd && (*pBegin & 0x1) != 0)
                pBegin++;

            // ��ǰ�ƶ�pEnd��ֱ����ָ������
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
    // ====================������: ����������������㷨��ҵ��====================
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
    //        // ����ƶ�pBegin
    //        while (pBegin < pEnd && !func(*pBegin))
    //            pBegin++;

    //        // ��ǰ�ƶ�pEnd
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