// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء���������
// {3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��

#pragma once

class _11_MinNumberInRotatedArray
{
	// ��������
	int MinInOrder(int* numbers, int index1, int index2)
	{
		int result = numbers[index1];
		for (int i = index1 + 1; i <= index2; ++i)
		{
			if (result > numbers[i])
				result = numbers[i];
		}

		return result;
	}

	int Min(int* numbers, int length)
	{
		// ���ֲ��ң�
		if (numbers == nullptr || length <= 0)
		{
			throw new std::exception("Invalid input!");
		}

		int Left = 0;
		int Right = length - 1;
		int Mid = Left;//��һ����С�����һ������˵��˳��ֱ�ӷ���
		while (numbers[Left] >= numbers[Right])
		{
			if (Right - Left == 1)
			{
				Mid = Right;
				break;
			}

			int Mid = (Left + Right) / 2;
			// ������ {1,0,1,1,1},Left��Right��Mid��ȣ�ֻ��˳�����
			if (numbers[Left] == numbers[Mid]&& numbers[Left] == numbers[Right]&& numbers[Right] == numbers[Mid])
			{
				return MinInOrder(numbers, Left, Right);
			}
			if (numbers[Mid] >= numbers[Right])
			{
				Left = Mid;
			}
			else if (numbers[Left] >= numbers[Mid])
			{
				Right = Mid;
			}
		}

		return numbers[Mid];
	}

	// ====================���Դ���====================
	void Test(int* numbers, int length, int expected)
	{
		int result = 0;
		try
		{
			result = Min(numbers, length);

			for (int i = 0; i < length; ++i)
				printf("%d ", numbers[i]);

			if (result == expected)
				printf("\tpassed\n");
			else
				printf("\tfailed\n");
		}
		catch (...)
		{
			if (numbers == nullptr)
				printf("Test passed.\n");
			else
				printf("Test failed.\n");
		}
	}

	int main(int argc, char* argv[])
	{
		// �������룬��������������һ����ת
		int array1[] = { 3, 4, 5, 1, 2 };
		Test(array1, sizeof(array1) / sizeof(int), 1);

		// ���ظ����֣������ظ������ָպõ���С������
		int array2[] = { 3, 4, 5, 1, 1, 2 };
		Test(array2, sizeof(array2) / sizeof(int), 1);

		// ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
		int array3[] = { 3, 4, 5, 1, 2, 2 };
		Test(array3, sizeof(array3) / sizeof(int), 1);

		// ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
		int array4[] = { 1, 0, 1, 1, 1 };
		Test(array4, sizeof(array4) / sizeof(int), 0);

		// �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
		int array5[] = { 1, 2, 3, 4, 5 };
		Test(array5, sizeof(array5) / sizeof(int), 1);

		// ������ֻ��һ������
		int array6[] = { 2 };
		Test(array6, sizeof(array6) / sizeof(int), 2);

		// ����nullptr
		Test(nullptr, 0, 0);

		return 0;
	}
};