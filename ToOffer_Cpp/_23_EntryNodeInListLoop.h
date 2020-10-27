// ������23�������л�����ڽ��
// ��Ŀ��һ�������а�����������ҳ�������ڽ�㣿���磬��ͼ3.8�������У�
// ������ڽ���ǽ��3��

#pragma once
#include "Utilities/list.h"

class _23_EntryNodeInListLoop
{
	// �ٿ���ָ�룬��2ָ��������ʱ���֤���Ǹ���
	// ��˫ָ�룬p1��ͷ��㣬�������Ļ���n���ڵ㣬p2������ǰ�ƶ�n����Ȼ��2����ͬ�ٶ��ƶ���������ʱ��������
	// ������Ļ��Ľڵ�������������ٿ�ʼ�������ٴλص��������ʱ�򣬾����õ��ڵ���
	
	// �ҵ�������
	ListNode* MeetingNode(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;

		ListNode* pSlow = pHead->m_pNext;
		if (pSlow == nullptr)
			return nullptr;

		ListNode* pFast = pSlow->m_pNext;
		while (pFast!=nullptr && pSlow != nullptr)
		{
			if (pFast == pSlow)
				return pFast;

			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
			if (pFast != nullptr)
				pFast = pFast->m_pNext;
		}
		return nullptr;
	}

	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		//�ٿ���ָ�룬��2ָ��������ʱ���֤���Ǹ���
		ListNode* pMeet = MeetingNode(pHead);
		if (pMeet == nullptr)
			return nullptr;
		// ������Ļ��Ľڵ�������������ٿ�ʼ�������ٴλص��������ʱ�򣬾����õ��ڵ���
		int loopCount = 1;
		while (pMeet != nullptr)
		{
			loopCount++;
			pMeet = pMeet->m_pNext;
		}

		// ��˫ָ�룬p1��ͷ��㣬�������Ļ���n���ڵ㣬p2������ǰ�ƶ�n����Ȼ��2����ͬ�ٶ��ƶ���������ʱ��������
		ListNode* pSlow = pHead;
		ListNode* pFast = pHead;
		while (pFast != nullptr && loopCount > 0)
		{
			pFast = pFast->m_pNext;
			loopCount--;
		}

		while (pFast != nullptr && pSlow != nullptr)
		{
			if (pFast == pSlow)
				return pFast;

			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
		}
		return pFast;
	}
};

