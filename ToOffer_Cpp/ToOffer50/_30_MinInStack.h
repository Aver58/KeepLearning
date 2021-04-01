// ������30������min������ջ
// ��Ŀ������ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min
// �������ڸ�ջ�У�����min��push��pop��ʱ�临�Ӷȶ���O(1)��
#pragma once
#include<stack>
#include <cassert>
using namespace std;

// ˼·���ø���ջ�������Сֵ��ÿѹ��һ��ֵ���ж��Ƿ�ȸ���ջ��ջ��Ԫ��С��
// ��ջ��С�Ļ�ֱ��ѹ�븨��ջ����Ȼ����ѹ��һ��ջ��Ԫ����ռλ����֤��ջ����֪����2С��Ԫ��
class _30_MinInStack
{
private:
    stack<int> m_DataStack;  // ����ջ�����ջ������Ԫ��
    stack<int> m_MinStack;   // ����ջ�����ջ����СԪ��
public:
    void Push(int value) 
    {
        m_DataStack.push(value);
        // ����Ԫ�ر�֮ǰ����СԪ��Сʱ������Ԫ�ز��븨��ջ�
        // �����֮ǰ����СԪ���ظ����븨��ջ��
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

