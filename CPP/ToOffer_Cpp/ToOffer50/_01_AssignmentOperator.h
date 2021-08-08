#pragma once
#include <string.h>
#include <stdio.h>
//题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    void Print();

private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if (pData == nullptr)  // 判断是否为空指针
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

/*
// 初级做法，未考虑内存不足时的异常安全性
CMyString& CMyString::operator=(const CMystring& str)
{
    // 判断是否为自身
    if(this == &str)
        return *this;

    // 赋值前先删除原有内容
    delete []m_pData;
    m_pData = nullptr;
    // 注意：这里如果内存不足，但是又已经把m_pData置为空了，返回的就是个空指针
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}
*/

// 高级做法 A = B
CMyString& CMyString::operator=(const CMyString& str)
{
    if (this != &str)
    {
        // 创建临时实例，相当于把要赋值的内容也传入了临时变量！
        CMyString strTemp(str);

        // 然后交换指向，新换旧，旧换新, 完成赋值。【保证内存不足时，不修改源实例】
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}

void CMyString::Print()
{
    printf("%s", m_pData);
}
