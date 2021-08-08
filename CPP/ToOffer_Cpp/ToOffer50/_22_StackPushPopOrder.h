#include<stack>
#include <iostream>
using namespace std;

class StackPushPopOrder
{
    public:
        void Push(int value);
        void Pop();
        bool IsPopOrder(const int* pPush,const int* pPop,int nLength);    
    private:
        stack<int> m_DataStack;
        stack<int> m_MinStack;
};