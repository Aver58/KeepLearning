#pragma once
#include <stack>
#include <queue>
#include <exception>
using namespace std;

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

template <typename T> class _09_QueueWithTwoStacks
{
private:
    stack<T> inputStack;
    stack<T> outputStack;

public:
    _09_QueueWithTwoStacks(void) {};
    ~_09_QueueWithTwoStacks(void) {};
    // 在队列末尾添加一个结点
    void appendTail(const T& node) 
    {
        inputStack.push(node);
    };

    // 删除队列的头结点
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
    // ====================测试代码====================
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

// 拓展 用两个队列实现栈
template <typename T> class _09_StackWithTwoQueues
{
private:
    Queue<T> inputQueue;
    Queue<T> outputQueue;

public:
    _09_StackWithTwoQueues(void) {};
    ~_09_StackWithTwoQueues(void) {};
    // 在队列末尾添加一个结点
    void appendTail(const T& node)
    {
        inputQueue.push(node);
    };

    // 删除队列的头结点
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