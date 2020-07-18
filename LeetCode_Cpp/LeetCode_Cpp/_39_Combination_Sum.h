#pragma once

/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

*/

#include "Global.h"

class _39_Combination_Sum
{
private:
	vector<vector<int>> resList;
	vector<int> candidates;
	vector<int> temp;
	int size;

public:
	void Test() {
		vector<int> head{ 2,3,6,7 };
		_39_Combination_Sum::combinationSum(head,7);
	}

	void DFS(int start, int target) {
		if (target < 0)
			return;

		if (target == 0) {
			resList.push_back(temp);
			return;
		}
		
		for (int i = start; i < size && target - candidates[i] >= 0; i++)
		{
			temp.push_back(candidates[i]);
			DFS(i, target - candidates[i]);
			temp.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		//1. 暴力法：罗列出所有子集，然后逐个判断总和是否为给定目标值

		//2. 回溯 + 剪枝(减法版) 12 ms 97%
		//思路： 以target为根节点做一棵树，每层减去所有节点，如果小于0，就剪掉
		//std::sort(candidates.begin(), candidates.end());// 还是不排序了，排序也很浪费时间
		this->candidates = candidates;
		this->size = candidates.size();
		DFS(0, target);

		//2. 回溯 + 剪枝(加法版)
		return resList;
	}
};

