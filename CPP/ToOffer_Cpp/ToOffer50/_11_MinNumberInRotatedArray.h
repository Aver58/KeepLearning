// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#pragma once

class _11_MinNumberInRotatedArray
{
	// 遍历查找
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
		// 二分查找，
		if (numbers == nullptr || length <= 0)
		{
			throw new std::exception("Invalid input!");
		}

		int Left = 0;
		int Right = length - 1;
		int Mid = Left;//第一个数小于最后一个数，说明顺序，直接返回
		while (numbers[Left] >= numbers[Right])
		{
			if (Right - Left == 1)
			{
				Mid = Right;
				break;
			}

			int Mid = (Left + Right) / 2;
			// 当遇到 {1,0,1,1,1},Left、Right、Mid相等，只能顺序查找
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

	// ====================测试代码====================
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
		// 典型输入，单调升序的数组的一个旋转
		int array1[] = { 3, 4, 5, 1, 2 };
		Test(array1, sizeof(array1) / sizeof(int), 1);

		// 有重复数字，并且重复的数字刚好的最小的数字
		int array2[] = { 3, 4, 5, 1, 1, 2 };
		Test(array2, sizeof(array2) / sizeof(int), 1);

		// 有重复数字，但重复的数字不是第一个数字和最后一个数字
		int array3[] = { 3, 4, 5, 1, 2, 2 };
		Test(array3, sizeof(array3) / sizeof(int), 1);

		// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
		int array4[] = { 1, 0, 1, 1, 1 };
		Test(array4, sizeof(array4) / sizeof(int), 0);

		// 单调升序数组，旋转0个元素，也就是单调升序数组本身
		int array5[] = { 1, 2, 3, 4, 5 };
		Test(array5, sizeof(array5) / sizeof(int), 1);

		// 数组中只有一个数字
		int array6[] = { 2 };
		Test(array6, sizeof(array6) / sizeof(int), 2);

		// 输入nullptr
		Test(nullptr, 0, 0);

		return 0;
	}
};