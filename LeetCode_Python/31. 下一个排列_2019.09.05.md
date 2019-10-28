## 程序员的自我修养:31. 下一个排列

-  所有的文字我都认识，连在一起我就不认识了。

### 方法一、数学计算 --36ms
- 复杂度分析：时间复杂度：O(n)空间复杂度：O(1) 
- 思路：最简单的思路，就是将其当做一个十进制的数去理解，找出比当前十进制数大的下一位，
- 比如12354，下一个就是12435。
- 源于离散数学及其应用的算法：
- （以1 2 3 5 4 为例）
- 从后往前寻找第一次出现的正序对：（找到 3,5）
- 之后因为从 5 开始都是逆序，所以把他们反转就是正序：1 2 3 4 5
- 之后 3 的位置应该是：在它之后的，比他大的最小值（4）
- 交换这两个值：得到 1 2 4 3 5
>- 执行用时 : 36 ms, 在所有 Python 提交中击败了72.31%的用户
>- 内存消耗 : 11.8 MB, 在所有 Python 提交中击败了23.53%的用户

```
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        if len(nums) < 2:
            return
        i = len(nums)-1
        while i > 0 and nums[i] <= nums[i-1]:
            i -= 1
        a, b = i, len(nums)-1
        while a < b:
            nums[a], nums[b] = nums[b], nums[a]
            a += 1
            b -= 1

        j = i-1
        for k in range(i, len(nums)):
            if nums[k] > nums[j]:
                nums[j], nums[k] = nums[k], nums[j]
                break
```

### 方法二：第一名

```
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        # 第一名
        if not nums:
            return []

        i = 0
        j = len(nums)-1
        while i < j:
            if nums[j-1] >= nums[j]:
                # 找到第一个正序对的索引
                j -= 1
            else:
                break

        if j == 0:
            # 数组是降序的
            nums.reverse()
            return nums

        i = j - 1
        while j < len(nums):
            if nums[j] > nums[i]:
                # 找到比nums[i]大的最小值索引
                j += 1
            else:
                break

        # 交换 i 和 j - 1
        nums[i], nums[j-1] = nums[j-1], nums[i]
        # 反转降序对
        j = len(nums)-1
        i += 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

        return nums
```

---

- 开始刷LeetCode，希望一起学习
[LeetCode github](https://github.com/Aver58/LeetCode)
>- 做题不是目的，目的是通过做题锻炼思维、掌握常用的算法。
>- 不要做过了就忘了，要变成自己的。