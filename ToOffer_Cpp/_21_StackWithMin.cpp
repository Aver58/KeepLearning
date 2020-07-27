//#include "_21_Stack.h"
//
//// 思路：用辅助栈来存放最小值，每压入一个值，判断是否比辅助栈的栈顶元素小，
//// 比栈顶小的话直接压入辅助栈，不然就再压入一个栈顶元素来占位，保证出栈后还能知道次2小的元素
//void StackWithMin::Push(int value)
//{
//    m_DataStack.push(value);
//    
//    if (m_MinStack.size() == 0 || value < m_MinStack.top()) {
//        m_MinStack.push(value);
//    }
//    else
//    {
//        m_MinStack.push(m_MinStack.top());
//    }
//} 
//
//void StackWithMin::Pop()
//{
//    if (m_DataStack.size() > 0) {
//        m_MinStack.pop();
//        m_DataStack.pop();
//    }
//}
//
//int StackWithMin::Min()
//{
//   if (m_MinStack.size() > 0) {
//        return m_MinStack.top();
//    } 
//}