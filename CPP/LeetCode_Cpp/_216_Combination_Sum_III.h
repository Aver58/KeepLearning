#pragma once

/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and 
each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include "Global.h"

class _216_Combination_Sum_III
{
private:
	vector<vector<int>> resList;
	vector<int> candidates;
	vector<int> temp;
	int size;
	int limitSize;

public:
	void Test() {
		_216_Combination_Sum_III::combinationSum3(3,9);
	}

	void DFS(int target,int start) {
		if (temp.size() > limitSize)
			return;
		
		if (target == 0)
		{
			if (temp.size() == limitSize)
				resList.push_back(temp);
			return;
		}

		for (int i = start; i < size && target - candidates[i] >= 0; i++)
		{
			temp.push_back(candidates[i]);
			DFS(target - candidates[i], i + 1);
			temp.pop_back();
		}
	}

	// k 只能使用几个数，n是目标值
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k > 9)
			return resList;

		this->candidates = {1,2,3,4,5,6,7,8,9};
		this->size = 9;
		this->limitSize = k;
		DFS(n,0);
		return resList;
	}
};