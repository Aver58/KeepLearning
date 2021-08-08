#pragma once

/*
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.
*/

#include "Global.h"

class _744_Find_Smallest_Letter_Greater_Than_Target
{

public:
	void Test() {
		vector<char> head{ 'c','f','j'};
		cout << nextGreatestLetter(head, 'j');
	}

	char nextGreatestLetter(vector<char>& letters, char target) {
		//1. 遍历
		int num = letters.size();
		//if (num <= 0)
		//	return letters[0];

		//for (size_t i = 0; i < num; i++)
		//{
		//	char letter = letters[i];
		//	if (letter > target)
		//		return letter;
		//}
		//return letters[0];

		//2. 二分
		int left = 0;
		int right = num - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			char letter = letters[mid];
			if (letter > target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return letters[left % num];
	}
};

