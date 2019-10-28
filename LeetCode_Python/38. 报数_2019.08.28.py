""""
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。


给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        # 1. 思路：24 ms
        input_str = '1'
        for i in range(1, n):
            # 外循环处理：input为输入值，output为输出值，say,count都初始化
            output_str = ''
            say = input_str[0]
            count = 1
            for j in range(1, len(input_str)):
                # 内循环处理：重复的话count += 1,不一致的话，count的归一，更新输出字符
                if input_str[j] == say:
                    count += 1
                else:
                    output_str += str(count) + say
                    say = input_str[j]
                    count = 1
            # 这里有点奇怪，因为是从第二个开始，如果只有一个，也要计数
            output_str += str(count) + say
            input_str = output_str
        return input_str

    # 2. 用一个convert函数作内循环，将遇到的数转化成要输出的数 28ms
    # 下一个数依赖上一个数的结果，最后输出最后一个结果
    # def convert(temp):
    #     result = ''
    #     pointer = 0
    #     count = 1
    #     while pointer < len(temp):
    #         if pointer+1 < len(temp) and temp[pointer] == temp[pointer + 1]:
    #             count += 1
    #             pointer += 1
    #         else:
    #             say = temp[pointer]
    #             pointer += 1
    #             result += str(count) + say
    #             count = 1
    #     return result
    #
    # result = []
    # result.append('1')
    # for i in range(1, n):
    #     result.append(convert(result[i - 1]))
    # return result[n - 1]


if __name__ == '__main__':
    nums = 6
    print(Solution().countAndSay(nums))
