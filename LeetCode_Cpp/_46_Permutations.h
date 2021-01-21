#pragma once

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.所有数都是独特的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _46_Permutations
{
private:
	vector<int> visited;

public:
	void Test() {
		vector<int> head{ 1,2,3 };
		vector<vector<int>> results = permute(head);
		for (size_t i = 0; i < results.size(); i++)
		{
			vector<int> temp = results[i];
			for (size_t j = 0; j < temp.size(); j++)
			{
				cout << temp[j];
			}
			cout << "\n";
		}
	}

	// 给定一个数组，列出所有全排列,
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		int len = nums.size();
		if (len == 0)
			return res;

		vector<int> temp;
		//空间换时间，记录当前数字是否用过，初始化为0
		vector<int> used(len, 0); 
		BackStack(res, nums, temp, used, 0, len);
		return res;
	}

	void BackStack(vector<vector<int>>& res, vector<int>& nums, vector<int> temp, vector<int> used, int depth, int len) {
		if (depth == len)
		{
			res.push_back(temp);
			return;
		}

		 //以叶子形式所有摊开，剪掉使用过的
		for (size_t i = 0; i < len; i++)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				temp.push_back(nums[i]);
				BackStack(res, nums, temp, used, depth + 1, len);
				//深度优先遍历回到上一层节点时需要状态重置
				temp.pop_back();
				used[i] = 0;
			}
		}
	}
};

