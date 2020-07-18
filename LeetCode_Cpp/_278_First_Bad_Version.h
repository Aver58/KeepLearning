#pragma once
/*
You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-bad-version
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _278_First_Bad_Version
{
public:
	// Forward declaration of isBadVersion API.
	//static bool isBadVersion(int version);

	static void Test() {
		_278_First_Bad_Version::firstBadVersion(5);
	}

	static int firstBadVersion(int n) {
		// 寻找左边边界，收紧右边边界
		//int left = 1;
		//int right = n;
		//while (left < right)
		//{
		//	int mid = left + (right - left) / 2;//防止溢出 (left+right)/2;
		//	if (isBadVersion(mid))
		//	{
		//		right = mid;
		//	}
		//	else
		//	{
		//		left = mid + 1;
		//	}
		//}
		//return left;
	}
};

