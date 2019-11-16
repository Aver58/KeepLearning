#pragma once

/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include "Global.h"

class _40_Combination_Sum_II
{
private:
	vector<vector<int>> resList;
	vector<int> candidates;
	vector<int> temp;
	int size;

public:
	void Test() {
		vector<int> head{ 10,1,2,7,6,1,5 };
		_40_Combination_Sum_II::combinationSum2(head,8);
	}

	void DFS(int target,int start) {
		if (0 == target )
		{
			resList.push_back(temp);
			return;
		}
		for (int i = start; i < size && target - candidates[i] >= 0; i++)
		{
			// 剪枝：连续相同数字会造成重复的组合数组
			if (i > start && candidates[i] == candidates[i - 1])
				continue;

			temp.push_back(candidates[i]);
			//本题与39.组合总和的区别：在于candidates 中的数字可以是否可以重复多次。
			DFS(target - candidates[i],i+1);// 注意i+1
			temp.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		// 每个数只能用一次
		// 1. 回溯+剪枝 8 ms 95.59%
		// 用减法
		std::sort(candidates.begin(), candidates.end());

		this->candidates = candidates;
		this->size = candidates.size();
		DFS(target, 0);
		return resList;
	}
};

