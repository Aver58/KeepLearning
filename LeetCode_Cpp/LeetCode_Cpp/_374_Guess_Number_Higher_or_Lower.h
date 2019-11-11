#include "Global.h"

/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example :

Input: n = 10, pick = 6
Output: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/guess-number-higher-or-lower
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#pragma once
class _374_Guess_Number_Higher_or_Lower
{
	// Forward declaration of guess API.
	// @param num, your guess
	// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
	//int guess(int num);

public:
	int guessNumber(int n) {
		//int left = 1;
		//int right = n;
		//while (left <= right)
		//{
		//	int mid = left + (right - left) / 2;
		//	int res = guess(mid);
		//	if (res == 0)
		//	{
		//		return mid;
		//	}
		//	else if (res == -1)
		//	{
		//		right = mid - 1;
		//	}
		//	else if (res == 1)
		//	{
		//		left = mid + 1;
		//	}
		//}
		//return -1;
	}
};

