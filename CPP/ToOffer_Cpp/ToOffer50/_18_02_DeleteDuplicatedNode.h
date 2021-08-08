// ������18��������ɾ���������ظ��Ľ��
// ��Ŀ����һ������������У����ɾ���ظ��Ľ�㣿

#pragma once
#include <cstdio>
#include "Utilities/list.h"

class _18_02_DeleteDuplicatedNode
{
	void DeleteDuplication(ListNode** pHead)
	{
		if (!pHead || !*pHead)
			return;

		// ˫ָ�룬һ��ָ��ǰһ���ڵ㣬һ��ָ��ֵ��һ������һ���ڵ�
		ListNode* pPreNode = nullptr;
		ListNode* pNode = *pHead;
		ListNode* pNext = nullptr;
		while (pNode != nullptr)
		{
			pNext = pNode->m_pNext;
			bool needDelete = false;

			if (pNext != nullptr && pNode->m_nValue == pNext->m_nValue)
				needDelete = true;

			if (!needDelete)
			{
				pPreNode = pNode;
			}
			else
			{
				int value = pNode->m_nValue;
				ListNode* pToBeDel = pNode;
				while (pToBeDel != nullptr && pToBeDel->m_nValue == value)
				{
					pNext = pToBeDel->m_pNext;

					delete pToBeDel;
					pToBeDel = nullptr;

					pToBeDel = pNext;
				}

				if (pPreNode == nullptr)
					*pHead = pNext;
				else
					pPreNode->m_pNext = pNext;
			}
			pNode = pNext;
		}
	}
};

