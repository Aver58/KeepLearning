// ������33�������������ĺ����������
// ��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
// ������򷵻�true�����򷵻�false���������������������������ֶ�������ͬ��

#pragma once
class _33_SquenceOfBST
{
	// ����������: ��������ֵʼ��С�ڸ��ڵ�
	// BST��Binary Search Tree������������
	bool VerifySquenceOfBST(int sequence[], int length)
	{
		if (sequence == nullptr || length <= 0)
			return false;
		
		// ���ڵ��ֵ�Ǻ�����������һ��
		int rootVal = sequence[length - 1];

		// ���������нڵ�ֵС�ڸ��ڵ�ֵ
		int leftLen = 0;
		for (leftLen = 0; leftLen < length - 1; leftLen++)
		{
			if (sequence[leftLen] > rootVal)
				break;
		}

		// ���������нڵ�ֵ���ڸ��ڵ�ֵ
		int rightLen = leftLen;
		for (; rightLen < length - 1; rightLen++)
		{
			if (sequence[rightLen] < rootVal)
				return false;
		}

		// �ݹ�������
		bool left;
		if (leftLen > 0)
			left = VerifySquenceOfBST(sequence, leftLen);
		// �ݹ�������
		bool right;
		if (rightLen < length - 1)
			right = VerifySquenceOfBST(sequence + rightLen, length - 1 - leftLen);

		return left && right;
	}
};

