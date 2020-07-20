#pragma once
#include <string.h>
#include <stdio.h>
//��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������
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
    if (pData == nullptr)  // �ж��Ƿ�Ϊ��ָ��
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
// ����������δ�����ڴ治��ʱ���쳣��ȫ��
CMyString& CMyString::operator=(const CMystring& str)
{
    // �ж��Ƿ�Ϊ����
    if(this == &str)
        return *this;

    // ��ֵǰ��ɾ��ԭ������
    delete []m_pData;
    m_pData = nullptr;
    // ע�⣺��������ڴ治�㣬�������Ѿ���m_pData��Ϊ���ˣ����صľ��Ǹ���ָ��
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}
*/

// �߼����� A = B
CMyString& CMyString::operator=(const CMyString& str)
{
    if (this != &str)
    {
        // ������ʱʵ�����൱�ڰ�Ҫ��ֵ������Ҳ��������ʱ������
        CMyString strTemp(str);

        // Ȼ�󽻻�ָ���»��ɣ��ɻ���, ��ɸ�ֵ������֤�ڴ治��ʱ�����޸�Դʵ����
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
