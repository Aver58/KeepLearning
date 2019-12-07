#pragma once

/*
Given a list of daily temperatures T, return a list such that, for each day in the input, 
tells you how many days you would have to wait until a warmer temperature. 
If there is no future day for which this is possible, put 0 instead.
给定一个数组 T 代表了未来几天里每天的温度值，要求返回一个新的数组 D，D 中的每个元素表示需要经过多少天才能等来温度的升高。
For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _739_Daily_Temperatures
{

public:
	void Test() {
		vector<int> head{ 73, 74, 75, 71, 69, 72, 76, 73 };
		_739_Daily_Temperatures::dailyTemperatures(head);
	}

	vector<int> dailyTemperatures(vector<int>& T) {
		//1. 暴力法O(n2) 每个去遍历

		//2. 一个堆栈 stack 算法复杂度是 O(n)216 ms 98%
		//从头到尾扫描一遍给定的数组 T，如果当天的温度比堆栈 stack 顶端所记录的那天温度还要高，那么就能得到结果。

		/*对第一个温度 23 度，堆栈为空，把它的下标压入堆栈；
			下一个温度 24 度，高于 23 度高，因此 23 度温度升高只需 1 天时间，把 23 度下标从堆栈里弹出，把 24 度下标压入；
			同样，从 24 度只需要 1 天时间升高到 25 度；
			21 度低于 25 度，直接把 21 度下标压入堆栈；
			19 度低于 21 度，压入堆栈；
			22 度高于 19 度，从 19 度升温只需 1 天，从 21 度升温需要 2 天；
			由于堆栈里保存的是下标，能很快计算天数；
			22 度低于 25 度，意味着尚未找到 25 度之后的升温，直接把 22 度下标压入堆栈顶端；
			后面的温度与此同理。
			该方法只需要对数组进行一次遍历，每个元素最多被压入和弹出堆栈一次，算法复杂度是 O(n)。
			*/
		stack<int> helpSatck;
		int length = T.size();
		vector<int> res(length);
		for (int i = 0; i < length; i++)
		{
			if (helpSatck.empty())
			{
				helpSatck.push(i);
			}
			else
			{
				while (!helpSatck.empty() && T[i] > T[helpSatck.top()])
				{
					res[helpSatck.top()] = i - helpSatck.top();
					helpSatck.pop();
				}
			
				helpSatck.push(i);
			}
		}

		return res;
	}
};

