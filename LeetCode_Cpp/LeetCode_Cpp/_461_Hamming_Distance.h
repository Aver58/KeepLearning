#pragma once
/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
	   ↑   ↑

The above arrows point to positions where the corresponding bits are different.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hamming-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _461_Hamming_Distance
{
public:
	static void Test() {
		_461_Hamming_Distance::hammingDistance(1,4);
	}

	static int hammingDistance(int x, int y) 
	{
		//1. 4 ms
		int n = x ^ y;
		int res = 0;
		while (n)
		{
			if (n % 2 != 0)res++;//若最低位是1 则余数不为0 res++
			n = n >> 1;//向右移1位
		}
		return res;
	}
};

