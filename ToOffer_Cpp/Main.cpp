#include "Main.h"
#include "_12_PrintOneToN.cpp"
#include "_14_OrderOddNumberFirst.cpp"
#include "_15_ChainList.cpp"
#include "_22_StackPushPopOrder.cpp"
#include <vector>

    // 12
    // PrintOneToN p(); 
    // PrintOneToN *p = new PrintOneToN();
    // p->Print1ToMaxDigit_1(2);
    
    // 14
    // OrderOddNumberFirst *p = new OrderOddNumberFirst();
    // int  var[6] = {0,5,2,6,4,5};
    // int *ptr = var;
    // p->ReOrder(var,5,IsOddNumber);

    // 构建链表
    // ListNode *pNewNode1 = new ListNode(1);
    // ListNode *pNewNode2 = new ListNode(2);
    // ListNode *pNewNode3 = new ListNode(3);
    // ListNode *pNewNode4 = new ListNode(4);
    // ListNode *pNewNode5 = new ListNode(5);
    // pNewNode1->m_next = pNewNode2;
    // pNewNode2->m_next = pNewNode3;
    // pNewNode3->m_next = pNewNode4;
    // pNewNode4->m_next = pNewNode5;


    // ListNode *pNew1 = new ListNode(6);
    // ListNode *pNew2 = new ListNode(7);
    // ListNode *pNew3 = new ListNode(8);
    // ListNode *pNew4 = new ListNode(9);
    // ListNode *pNew5 = new ListNode(10);

    // pNew1->m_next = pNew2;
    // pNew2->m_next = pNew3;
    // pNew3->m_next = pNew4;
    // pNew4->m_next = pNew5;

    // ChainList *p = new ChainList();
    // 15 输入一个链表，输出链表的倒数第K个节点
    // ListNode *pHead = p->FindKthInTaik(pNewNode1,2);
    // 16 翻转链表
    // ListNode *pHead = p->ReverseList(pNewNode1);
    // 17 合并两个有序链表
    // ListNode *pHead = p->MergeOrderedList(pNewNode1,pNew1);
    // while(pHead!=NULL)
    // {
    //     cout<<pHead->m_value;
    //     pHead = pHead->m_next;
    // }
    // cout<<pHead->m_value;
   
  int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator iterator;
        for (iterator = nums.begin(); iterator != nums.end(); iterator++) {
            if (*iterator == val) {
                //移除当前迭代项，返回下一项
                iterator = nums.erase(iterator);
                //返回上一项，这样在iterator++的时候才能得到正确的项
                iterator--;
            }
        }

        return nums.size();
}  

// vector<int> plusOne(vector<int>& digits) {
     
//      for(int i = 0; i < digits.; i++)
//      {
//          /* code */
//      }
     
// }



int main()
{
     vector<int>obj;//创建一个向量存储容器 int
     obj.push_back(1);
     obj.push_back(4);
    getchar();
    return 0;
}
