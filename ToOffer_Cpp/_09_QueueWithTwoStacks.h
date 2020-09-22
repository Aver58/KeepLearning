#pragma once
#include <stack>
#include <queue>
#include <exception>
using namespace std;

// ������9��������ջʵ�ֶ���
// ��Ŀ��������ջʵ��һ�����С����е��������£���ʵ��������������appendTail
// ��deleteHead���ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ��ܡ�

template <typename T> class _09_QueueWithTwoStacks
{
private:
    stack<T> inputStack;
    stack<T> outputStack;

public:
    _09_QueueWithTwoStacks(void) {};
    ~_09_QueueWithTwoStacks(void) {};
    // �ڶ���ĩβ���һ�����
    void appendTail(const T& node) 
    {
        inputStack.push(node);
    };

    // ɾ�����е�ͷ���
    T deleteHead() 
    {
        if (outputStack.size() <= 0)
        {
            while (inputStack.size() > 0)
            {
                T& data = inputStack.top();
                inputStack.pop();
                outputStack.push(data);
            }
        }

        if (outputStack.size() == 0)
            throw new exception("queue is empty");

        T head = outputStack.top();
        outputStack.pop();

        return head;
    };
 /*   
    // ====================���Դ���====================
    void Test(char actual, char expected)
    {
        if (actual == expected)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }

    void Test()
    {
        _09_QueueWithTwoStacks<char> queue;

        queue.appendTail('a');
        queue.appendTail('b');
        queue.appendTail('c');

        char head = queue.deleteHead();
        Test(head, 'a');

        head = queue.deleteHead();
        Test(head, 'b');

        queue.appendTail('d');
        head = queue.deleteHead();
        Test(head, 'c');

        queue.appendTail('e');
        head = queue.deleteHead();
        Test(head, 'd');

        head = queue.deleteHead();
        Test(head, 'e');
    }*/
};

// ��չ ����������ʵ��ջ
template <typename T> class _09_StackWithTwoQueues
{
private:
    Queue<T> inputQueue;
    Queue<T> outputQueue;

public:
    _09_StackWithTwoQueues(void) {};
    ~_09_StackWithTwoQueues(void) {};
    // �ڶ���ĩβ���һ�����
    void appendTail(const T& node)
    {
        inputQueue.push(node);
    };

    // ɾ�����е�ͷ���
    T deleteHead()
    {
        if (outputQueue.size() <= 0)
        {
            while (inputQueue.size() > 0)
            {
                T& data = inputQueue.top();
                inputQueue.pop();
                outputQueue.push(data);
            }
        }

        if (outputQueue.size() == 0)
            throw new exception("stack is empty");

        T head = outputQueue.top();
        outputQueue.pop();

        return head;
    }

};