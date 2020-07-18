#include "Global.h"

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/
#pragma once
class _300_Longest_Increasing_Subsequence
{
public:
    void Test() {
        vector<int> Input{ 10,9,2,5,3,7,101,18 };
        _300_Longest_Increasing_Subsequence::lengthOfLIS(Input);
    }

    // 定义哈希表 cache，用来保存计算结果
    static map<int, int> cache;

    int lengthOfLIS(vector<int>& nums) {
        //最长上升子序列的长度。
        //1. 暴力法 找出所有的子序列，然后从中返回一个最长的。
        /*int resLen = 0;
        int numLen = nums.size();
        vector<vector<int>> res;
        for (size_t i = 0; i < numLen; i++)
        {
            int cur = nums[i];
            for (size_t j = i + 1; j < numLen; j++)
            {
                if (res.size() > 0)
                {
                    for (size_t k = 0; k < res.size(); k++)
                    {
                        if (cur > res[i].back())
                        {
                            res[i].push_back(cur);
                            resLen = max(res[i].size(),resLen);
                        }
                    }
                }
                else
                {
                    if (nums[j] > cur)
                    {
                        vector<int> temp;
                        temp.push_back(cur);
                        temp.push_back(nums[j]);
                        res.push_back(temp);
                        resLen = 2;
                    }
                }
            }
        }
        return resLen;*/

        // 2. 递归 2^n
       /* max = 1;
        f(nums, nums.size());
        return max;*/

        //3.记忆化 n^2

        //4.动态规划 ：自底向上（Bottom - Up）
        int n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());

        // 初始化 dp 数组里的每个元素的值为 1，即以每个元素作为结尾的最长子序列的长度初始化为 1
        //for (i = 0; i < n; i++) dp[i] = 1;

        //// 自底向上地求解每个子问题的最优解
        //for (i = 0; i < n; i++) {
        //    // 遍历中遇到的每个元素 nums[j] 与 nums[i] 比较，若 nums[j] < nums[i]，说明 nums[i] 有机会构成上升序列，若新的上升序列比之前计算过的还要长，更新一下，保存到 cache 数组
        //    for (j = 0; j < i; j++) {
        //        if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
        //            dp[i] = dp[j] + 1;
        //        }
        //    }
        //    // 用当前计算好的长度与全局的最大值进行比较  
        //    max = Math.max(max, dp[i]);
        //}

        //// 最后得出最长的上升序列的长度
        //return max;
    }

private:
    //int f(vector<int>& nums, int n)
    //{
    //    if (n <= 1)
    //        return n;

    //    int result = 0, maxEndingHere = 1;
    //    //从头遍历数组，递归求出以每个点为‘结尾’的子数组中最长上升序列的长度
    //    //比如以9为结尾，就只有9，长度为1；以5结尾，有2，5，所以长度为2；
    //    //input : 10,9,2,5,3,7,101,18
    //    //dp    :  1,1,1,2,2,3,  4, 4
    //    for (size_t i = 1; i < n; i++)
    //    {
    //        result = f(nums, i);
    //        if (nums[i-1] < nums[n-1] && result + 1 > maxEndingHere)
    //        {
    //            maxEndingHere = result + 1;
    //        }
    //    }
    //    // 判断一下，如果那个数比目前最后一个数要小，那么就能构成一个新的上升子序列 
    //    max = min(max, maxEndingHere);
    //    return maxEndingHere;
    //}
};