/*
Write a function that reverses a string. The input string is given as an array of characters s.

?

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
?

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
?

Follow up: Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#pragma once
#include "Global.h"
class _344_Reverse_String
{
public:
void Test(){
	vector<char> a {'h','e','l','l','o'};
	reverseString(a);
	for (auto c:a)
	{
		cout<<c;
	}
};
    
	void reverseString(vector<char>& s) {
		//不要分配额外的空间，时间复杂度为o（1）
		int n = s.size();
		for (int i = 0; i < n/2; i++)
		{
			char temp = s[i];
			s[i] = s[n-1-i];
			s[n-1-i] = temp;
		}
    }
};

