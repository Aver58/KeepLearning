#include "_15_ChainList.h"

// 输入一个链表，输出链表的倒数第K个节点

// 1.老牛拖车法，用2个指针，中间始终距离k-1距离，
// 这样，当前一个指针走的尾部，后一个指针指向的就是倒数第k个节点
ListNode* ChainList::FindKthInTaik(ListNode* pListHead,int k)
{
    // 空指针
    if(pListHead == NULL || k == 0)
        return NULL;

    ListNode* pAhead = pListHead;
    ListNode* pBehind = NULL;
    
    for(int i = 0;i<k - 1; i++)
    {
        // k>链表长度
        if(pAhead->m_next != NULL)
            pAhead = pAhead->m_next;
        else
            return NULL;
    }

    pBehind = pListHead;
    // 边界
    while(pAhead->m_next != NULL)
    {
        pAhead = pAhead->m_next;
        pBehind = pBehind->m_next;
    }
    return pBehind;
}

// 求链表的中间节点。（如果节点总数为奇数，返回中间节点，偶数返回中间的任意一个。）
// 用两个指针，一个一次走一个，后一个一次走2个

// 判断一个单向链表是否闭环。
// 用两个指针，一个指向链表头，后一个一直走，后面的追上了前面就是闭环


// 16 翻转链表
ListNode* ChainList::ReverseList(ListNode* pHead)
{
    // 空指针
    if(pHead == NULL)
        return NULL;

    // 翻转后的头节点
    ListNode* pReversedHead = NULL;
    ListNode* pPrev = NULL;
    ListNode* pNext = NULL;
    ListNode* pCurrent = pHead;
    while(pCurrent != NULL)
    {
        pNext = pCurrent->m_next;
        if(pNext == NULL)
            pReversedHead = pCurrent;
            
        pCurrent->m_next = pPrev;
        
        pPrev = pCurrent;
        pCurrent = pNext;
    }

    return pReversedHead;
}

// 17 合并两个有序链表
    // 小的做头节点，递归赋值
ListNode* ChainList::MergeOrderedList(ListNode* pHead1,ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;

    ListNode *MergeHead = NULL;
    if(pHead1->m_value < pHead2->m_value)
    {
        MergeHead = pHead1;
        MergeHead->m_next = MergeOrderedList(pHead1->m_next,pHead2);
    }
    else
    {
        MergeHead = pHead2;
        MergeHead->m_next = MergeOrderedList(pHead1,pHead2->m_next);
    }

    return MergeHead;
}