// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。
#pragma once
#include<stack>
#include <cassert>
using namespace std;

// 思路：用辅助栈来存放最小值，每压入一个值，判断是否比辅助栈的栈顶元素小，
// 比栈顶小的话直接压入辅助栈，不然就再压入一个栈顶元素来占位，保证出栈后还能知道次2小的元素
class _30_MinInStack
{
private:
    stack<int> m_DataStack;  // 数据栈，存放栈的所有元素
    stack<int> m_MinStack;   // 辅助栈，存放栈的最小元素
public:
    void Push(int value) 
    {
        m_DataStack.push(value);
        // 当新元素比之前的最小元素小时，把新元素插入辅助栈里；
        // 否则把之前的最小元素重复插入辅助栈里
        if (m_MinStack.size() == 0 || value < m_MinStack.top())
        {
            m_MinStack.push(value);
        }
        else
        {
            m_MinStack.push(m_MinStack.top());
        }
    };
    void Pop() 
    {
        if (m_DataStack.size() > 0 && m_MinStack.size() > 0)
        {
            m_DataStack.pop();
            m_MinStack.pop();
        }
    };
    int Min() 
    {
        if (m_MinStack.size() > 0)
            m_MinStack.top();
    };
};

