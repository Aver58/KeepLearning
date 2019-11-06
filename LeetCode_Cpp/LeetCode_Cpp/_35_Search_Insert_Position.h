/*
Given a sorted array and a target value, 
return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _35_Search_Insert_Position {
public:
	static void Test() {
		vector<int> Input;//创建一个向量存储容器 int
		Input.push_back(1);
		Input.push_back(3);
		Input.push_back(5);
		Input.push_back(6);
		std::cout << searchInsert(Input,2);
	}

	static int searchInsert(vector<int>& nums, int target) {
		//1.遍历 
		//int n = nums.size();
		//for (int i = 0; i < n; i++)
		//{
		//	if (target <= nums[i])
		//	{
		//		return i;
		//	}
		//}
		//return n;

		//2. 二分法 4 ms 97%
		int n = nums.size();
		if (n <= 0)
			return 0;

		if (target > nums[n - 1])
			return n;

		int left = 0;
		int right = n - 1;
		int middle = 0;
		int middleIndex = 0;
		// 奇数偶数
		while (left <= right)
		{
			middleIndex = (left + right) / 2;
			middle = nums[middleIndex];
			if (target == middle)
			{
				return middleIndex;
			}
			else if(target > middle)
			{
				left = middleIndex + 1;
			}
			else
			{
				right = middleIndex - 1;
			}
		}
		return left;
	}
};
