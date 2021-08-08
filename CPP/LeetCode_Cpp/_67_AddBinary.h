// 67. 二进制求和

// 给定两个二进制字符串，返回他们的和（用二进制表示）。

// 输入为非空字符串且只包含数字 1 和 0。

// 示例 1:

// 输入: a = "11", b = "1"
// 输出: "100"
// 示例 2:

// 输入: a = "1010", b = "1011"
// 输出: "10101"

// using namespace std;
#include "Global.h"

class _67_AddBinary {
public:
    string addBinary(string a, string b) {
       string sumString = "";
       int leftSize = a.size();
       int rightSize = b.size();
       int longSize = leftSize > rightSize ? leftSize:rightSize;
       int shortSize = leftSize > rightSize ? rightSize:leftSize;
       for(int i = 0; i < longSize; i++)
       {
            if (i > shortSize - 1) break;
            int result = a[i]- '0' + b[i] - '0';
            if (result > 1) {
                sumString += 
            }
            
                       
       }
       // 1. 转为十进制数字，计算后，再转回二进制（考虑大数问题）
       // 2. 遍历，逢二进一
    }

    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        int p = 0, q = 0;
        while(m >= 0 || n >= 0)
        {
            if(m >= 0) p = a[m] - '0';
            else p = 0;
            if(n >= 0) q = b[n] - '0';
            else q = 0;
            res = to_string((p + q + carry)%2) + res;//反向
            carry = (p + q + carry)/2;
            m--;
            n--;
        }//while
        if(carry == 1) res = '1' + res;
        return res;
    }
};

