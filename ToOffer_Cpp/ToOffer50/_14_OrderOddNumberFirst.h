#include <iostream>
using namespace std;
#include "Swap.h"

class OrderOddNumberFirst
{
    public:
        OrderOddNumberFirst();
        void ReOrder(int*,int n,bool (*func)(int));

};

// 输入整形数组，实现奇数在前，偶数在后
void OrderOddNumberFirst::ReOrder(int *pData, int length,bool (*func)(int))
{
    if(pData == NULL || length == 0)
        return;

    int *firstPtr = pData;
    int *lastPtr = pData + length-1;
    while(firstPtr < lastPtr){
        // 左边遇到第一个偶数
        while(!func(*firstPtr) && firstPtr < lastPtr)
        {
            firstPtr++;
        }
        // 右边遇到第一个奇数
        if(func(*lastPtr) && firstPtr < lastPtr){
            lastPtr--;
        }
        //交换
        if(firstPtr < lastPtr)
            Swap(*firstPtr,*lastPtr);
    }

    for(int i = 0; i<length; i ++)
    {
        cout<<*(pData + i)<<endl;
    }
}

// 奇数判断
bool IsOddNumber(int num)
{
    return (num & 1) == 1;
}