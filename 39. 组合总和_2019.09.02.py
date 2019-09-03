""""
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # 1. 回溯 + 剪枝 176 ms 15% 11.8MB 26.13%
        # 思路①： 以target为根节点做一棵树，每层减去所有节点，如果小于0，就剪掉
        # candidates.sort()
        # n = len(candidates)
        # res = []
        # def backtrack(i, tmp_reduce, tmp_list):
        #     if tmp_reduce < 0 or i == n:
        #         return
        #     if tmp_reduce == 0:
        #         res.append(tmp_list)
        #         return
        #     # 回溯所有的组合
        #     for j in range(i, n):
        #         if tmp_reduce - candidates[j] < 0:
        #             break
        #         backtrack(j, tmp_reduce - candidates[j], tmp_list + [candidates[j]])
        # backtrack(0, target, [])
        # return res
        # 2. 思路②：加法 同上52 ms  77.53%   11.8MB 26.13%
        # candidates.sort()
        # n = len(candidates)
        # res = []
        # def backtrack(i, tmp_sum, tmp_list):
        #     # 和大了就剪枝
        #     if tmp_sum > target or i == n:
        #         return
        #     if tmp_sum == target:
        #         res.append(tmp_list)
        #         return
        #     # 所有都回溯
        #     for j in range(i, n):
        #         if tmp_sum + candidates[j] > target:
        #             # 剪掉 大的
        #             break
        #         backtrack(j, tmp_sum + candidates[j], tmp_list + [candidates[j]])
        # backtrack(0, 0, [])
        # return res

        # 4.第一名
        # candidates.sort()
        # res = []
        # st = []
        # n = len(candidates)
        # i = 0
        # while True:
        #     if target == 0:
        #         res.append([candidates[i] for i in st])
        #         i = st.pop()
        #         target += candidates[i]
        #         i += 1
        #     elif i == n or candidates[i] > target:
        #         if len(st) == 0:
        #             return res
        #         i = st.pop()
        #         target += candidates[i]
        #         i += 1
        #     elif candidates[i] <= target:
        #         st.append(i)
        #         target -= candidates[i]
        #
        candidates.sort()
        n = len(candidates)
        res = []
        def helper(i, tmp_sum, tmp):
            if tmp_sum > target or i == n:
                return
            if tmp_sum == target:
                res.append(tmp)
                return
            if tmp_sum + candidates[i] > target:
                return
            helper(i,  tmp_sum + candidates[i], tmp + [candidates[i]])
            helper(i+1, tmp_sum, tmp)
        helper(0, 0, [])
        return res


if __name__ == '__main__':
    candidates = [2, 3, 5]
    target = 8
    print(Solution().combinationSum(candidates, target))
