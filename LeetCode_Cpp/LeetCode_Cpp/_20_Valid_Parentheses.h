#pragma once
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _20_Valid_Parentheses
{
private:
	map<char, char> ValidMap = {
	{'(', ')'},
	{'[' , ']'},
	{'{' , '}'},
	};

public:
	void Test() {
		string s = "]";
		_20_Valid_Parentheses::isValid(s);
	}

	bool isValid(string s) {
		//1. 先建立一个映射表，key是左括号，value是右括号 4 ms 76%
		//然后遇到左括号入栈，遇到右括号出栈，最后栈如果是空的就是valid的

		stack<int> stack;
		for (char oneChar : s)
		{
			map<char, char>::iterator it = ValidMap.find(oneChar);
			if (it==ValidMap.end())
			{
				if (stack.empty())
					return false;

				if (ValidMap[stack.top()] != oneChar)
					return false;

				stack.pop();
			}
			else
			{
				stack.push(oneChar);
			}
		}

		return stack.empty();
	}
};

