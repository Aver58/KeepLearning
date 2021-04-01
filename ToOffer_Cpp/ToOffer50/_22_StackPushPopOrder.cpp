#include "_22_StackPushPopOrder.h"

// 判断一个序列是不是栈的弹出序列：
// 如果下一个数字刚好是栈顶元素，直接弹出
// 不是的话，把未入栈的压入，直到栈顶元素是下一个数字，
// 如果到最后都没有找到数字，那就说明不是。

//pPush为输入元素的头指针,例如1,2,3,4,5
//pPop为输出序列的头指针，例如4,5,3,2,1
bool StackPushPopOrder::IsPopOrder(const int* pPush,const int* pPop,int nLength)
{
    if(nLength == 0 ||
        pPush == nullptr ||
        pPop == nullptr)
        return false;

    stack<int> stackData;
    const int* pNewPush = pPush;
    const int* pNewPop = pPop;

    while(pNewPop - pPop < nLength){
        // 当辅助栈的栈顶元素不是要弹出的元素
        // 先压入一些数字入栈
        while(stackData.empty() || 
            *pNewPop != stackData.top()){
            // 如果所有数字都压入辅助栈了，退出循环
            if(pNewPop - pPop == nLength)
                break;
            stackData.push(*pNewPush);
            pNewPush++;            
        }

        // 如果下一个数字刚好是栈顶元素，直接弹出
        if (*pNewPop != stackData.top()) 
            break;

        stackData.pop();
        pNewPop++;
    }
    // 如果到最后都没有找到数字，那就说明不是。
    if (stackData.empty() && pNewPop - pPop == nLength) 
        return true;

    return false;
}

// ====================测试代码====================
//IsPopOrder
//void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
//{
//    StackPushPopOrder *p = new StackPushPopOrder();
//    if(testName != nullptr)
//        printf("%s begins: ", testName);
//
//    if(p->IsPopOrder(pPush, pPop, nLength) == expected)
//        printf("Passed.\n");
//    else
//        printf("failed.\n");
//}

//void Test1()
//{
//    const int nLength = 5;
//    int push[nLength] = {1, 2, 3, 4, 5};
//    int pop[nLength] = {4, 5, 3, 2, 1};
//    
//    Test("Test1", push, pop, nLength, true);
//}
//
//void Test2()
//{
//    const int nLength = 5;
//    int push[nLength] = {1, 2, 3, 4, 5};
//    int pop[nLength] = {3, 5, 4, 2, 1};
//    
//    Test("Test2", push, pop, nLength, true);
//}
//
//void Test3()
//{
//    const int nLength = 5;
//    int push[nLength] = {1, 2, 3, 4, 5};
//    int pop[nLength] = {4, 3, 5, 1, 2};
//    
//    Test("Test3", push, pop, nLength, false);
//}
//
//void Test4()
//{
//    const int nLength = 5;
//    int push[nLength] = {1, 2, 3, 4, 5};
//    int pop[nLength] = {3, 5, 4, 1, 2};
//    
//    Test("Test4", push, pop, nLength, false);
//}
//
//// push和pop序列只有一个数字
//void Test5()
//{
//    const int nLength = 1;
//    int push[nLength] = {1};
//    int pop[nLength] = {2};
//
//    Test("Test5", push, pop, nLength, false);
//}
//
//void Test6()
//{
//    const int nLength = 1;
//    int push[nLength] = {1};
//    int pop[nLength] = {1};
//
//    Test("Test6", push, pop, nLength, true);
//}
//
//void Test7()
//{
//    Test("Test7", nullptr, nullptr, 0, false);
//}

//int main_22()
//{
//    Test1();
//    Test2();
//    Test3();
//    Test4();
//    Test5();
//    Test6();
//    Test7();
//
//    getchar();
//    return 0;
//}