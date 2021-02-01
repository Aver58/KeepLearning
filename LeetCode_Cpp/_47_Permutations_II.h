/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#pragma once
#include "Global.h"

class _47_Permutations_II
{

public:
	void Test() {
		vector<int> head{ 1,2,3 };
		vector<vector<int>> results = permuteUnique(head);
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

    vector<vector<int>> permuteUnique(vector<int>& nums) {

    }
};