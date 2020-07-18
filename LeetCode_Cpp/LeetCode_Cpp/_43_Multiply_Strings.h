#pragma once

/*
Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library 
or convert the inputs to integer directly.
*/

#include "Global.h"

class _43_Multiply_Strings
{
public:
	void Test() {
		string num1 = "123";
		string num2 = "456";
		_43_Multiply_Strings::multiply(num1, num2);
	}

	string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")return "0";
        string ans = "";
        int c = 0;
        int i = num1.size() + num2.size() - 2;
        int x = 0;
        while (i >= 0) {
            x = c;
            //cout<<x<<"."<<endl;
            for (int j = i < num1.size() ? i : (num1.size() - 1); i - j < num2.size() && j >= 0; j--) {
                x += ((num1[j] - '0') * (num2[i - j] - '0'));
                //cout<<j<<" "<<i-j;
                //cout<<"="<<x<<endl;
                //cout<<num1[j]<<" "<<num2[i-j];
                //cout<<"="<<x<<endl;
            }
            c = x / 10;
            x = x % 10;
            char a = '0' + x;
            ans = a + ans;
            //cout<<i<<endl;
            i--;
        }
        if (c != 0)ans = char(c + '0') + ans;
        return ans;
	}
};

