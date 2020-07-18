#include <iostream>
using namespace std;

struct ListNode
{
    int m_value;
    ListNode* m_next;
    ListNode(int n)
    {
        m_value = n;
        m_next = NULL;
    }
};

class ChainList
{
    public:
        ChainList(){};
        ListNode* ReverseList(ListNode*);
        ListNode* FindKthInTaik(ListNode*,int);
        ListNode* MergeOrderedList(ListNode*,ListNode*);
};