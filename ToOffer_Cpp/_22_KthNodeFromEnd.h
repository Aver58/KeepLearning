// ������22�������е�����k�����
// ��Ŀ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
// �����1��ʼ�������������β����ǵ�����1����㡣����һ��������6����㣬
// ��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3�������
// ֵΪ4�Ľ�㡣

#pragma once
#include <cstdio>
#include "Utilities\List.h"

class _22_KthNodeFromEnd
{
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		if (pListHead == nullptr || k <= 0)
			return nullptr;
	
		// ˫ָ�롾��ţ�ϳ���������ָ�����ָ���k���ڵ㣬����ָ�뵽ĩβ��ʱ����ָ�����Ҫ��ֵ
		ListNode* pFast = pListHead;
		ListNode* pSlow = pListHead;
		int index = 0;
		while (pFast != nullptr)
		{
			pFast = pFast->m_pNext;
			index++;
			if (index >= k)
			{
				pSlow = pSlow->m_pNext;
			}
		}
		// ��ָ�뻹û�ߵ�kλ��
		if (index < k)
			return nullptr;
		
		return pSlow;
	}
};

