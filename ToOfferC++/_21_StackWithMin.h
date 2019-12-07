#include<stack>
#include <iostream>
using namespace std;

class StackWithMin
{
    public:
        StackWithMin();
        void Push(int value);
        void Pop();
        int Min();
    
    private:
        stack<int> m_DataStack;
        stack<int> m_MinStack;
};