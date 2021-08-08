/*
Count the number of prime numbers less than a non-negative number, n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:
0 <= n <= 5 * 106
*/

#pragma once
#include "Global.h"

class _204_Count_Primes
{
public:
	void Test() {
		cout << countPrimes(100);
	}

	//性质：除了1和本身，不能被其他数整除
	bool IsPrime(int n) {
		for (int i = 2; i * i <= n; i++)
		{
			if (n%i==0)
				return false;
		}
		return true;
	}

	//埃氏筛:如果 xx 是质数，那么大于 xx 的 xx 的倍数 2x,3x,… 一定不是质数
	int countPrimes(int n) {
		int count = 0;
		vector<int> isPrime(n, 1);
		for (int i = 2; i < n; i++)
		{
			if (isPrime[i]) {
				count += 1;
				if ((long long)i * i < n) {
					for (int j = i * i; j < n; j += i) {
						isPrime[j] = 0;
					}
				}
			}
		}
		return count;
	}
};