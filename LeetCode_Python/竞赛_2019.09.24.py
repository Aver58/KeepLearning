""""
1. 猜数字

小A 和 小B 在玩猜数字。小B 每次从 1, 2, 3 中随机选择一个，小A 每次也从 1, 2, 3 中选择一个猜。他们一共进行三次这个游戏，请返回 小A 猜对了几次？



输入的guess数组为 小A 每次的猜测，answer数组为 小B 每次的选择。guess和answer的长度都等于3。



示例 1：

输入：guess = [1,2,3], answer = [1,2,3]
输出：3
解释：小A 每次都猜对了。


示例 2：

输入：guess = [2,2,3], answer = [3,2,1]
输出：1
解释：小A 只猜对了第二次。


限制：

guess的长度 = 3
answer的长度 = 3
guess的元素取值为 {1, 2, 3} 之一。
answer的元素取值为 {1, 2, 3} 之一。
"""


# class Solution(object):
#     def game(self, guess, answer):
#         """
#         :type guess: List[int]
#         :type answer: List[int]
#         :rtype: int
#         """
#         res = 0
#         for i in range(len(guess)):
#             if guess[i] == answer[i]:
#                 res += 1
#
#         return res


""""
2. 分式化简

有一个同学在学习分式。他需要将一个连分数化成最简分数，你能帮助他吗？



连分数是形如上图的分式。在本题中，所有系数都是大于等于0的整数。

 

输入的cont代表连分数的系数（cont[0]代表上图的a0，以此类推）。返回一个长度为2的数组[n, m]，使得连分数的值等于n / m，且n, m最大公约数为1。

 

示例 1：

输入：cont = [3, 2, 0, 2]
输出：[13, 4]
解释：原连分数等价于3 + (1 / (2 + (1 / (0 + 1 / 2))))。注意[26, 8], [-13, -4]都不是正确答案。
示例 2：

输入：cont = [0, 0, 3]
输出：[3, 1]
解释：如果答案是整数，令分母为1即可。
限制：

cont[i] >= 0
1 <= cont的长度 <= 10
cont最后一个元素不等于0
答案的n, m的取值都能被32位int整型存下（即不超过2 ^ 31 - 1）。
"""

#
# class Solution(object):
#     def fraction(self, cont):
#         """
#         :type cont: List[int]
#         :rtype: List[int]
#         """
#         # 1. 递归求分母，然后最后算出分子
#         if cont is None:
#             return None
#         son = 1 # 分子
#         mum = 1 # 分母
#         for i in range(len(cont) - 1, -1, -1):
#             if i > 1:
#                 mum = cont[i] + son / mum
#                 son = cont[i - 1] * mum + son
#                 mum, son = son, mum
#         return [son, mum]



""""
3. 机器人大冒险

力扣团队买了一个可编程机器人，机器人初始位置在原点(0, 0)。小伙伴事先给机器人输入一串指令command，机器人就会无限循环这条指令的步骤进行移动。指令有两种：

U: 向y轴正方向移动一格
R: 向x轴正方向移动一格。
不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。

给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。

 

示例 1：

输入：command = "URR", obstacles = [], x = 3, y = 2
输出：true
解释：U(0, 1) -> R(1, 1) -> R(2, 1) -> U(2, 2) -> R(3, 2)。
示例 2：

输入：command = "URR", obstacles = [[2, 2]], x = 3, y = 2
输出：false
解释：机器人在到达终点前会碰到(2, 2)的障碍物。
示例 3：

输入：command = "URR", obstacles = [[4, 2]], x = 3, y = 2
输出：true
解释：到达终点后，再碰到障碍物也不影响返回结果。
 

限制：

2 <= command的长度 <= 1000
command由U，R构成，且至少有一个U，至少有一个R
0 <= x <= 1e9, 0 <= y <= 1e9
0 <= obstacles的长度 <= 1000
obstacles[i]不为原点或者终点
"""


# class Solution(object):
#     def robot(self, command, obstacles, x, y):
#         """
#         :type command: str
#         :type obstacles: List[List[int]]
#         :type x: int
#         :type y: int
#         :rtype: bool
#         """
#         intMax = 10**9
#         if command is None or len(command) <= 0:
#             return False
#
#         if x > intMax or y > intMax or x < 0 or y < 0:
#             return False
#         if [x, y] in obstacles:
#             return False
#         # 欠考虑了，我觉得，应该有更好的解决方案
#         i = 0
#         n = len(command)
#         cMap = {}
#         for i in command:
#             if i not in cMap:
#                 cMap[i] = 1
#             else:
#                 cMap[i] += 1
#
#         curPosX, curPosY = 0, 0
#         while True:
#             if curPosX == x and curPosY == y:
#                 return True
#             if curPosX > intMax or curPosY > intMax:
#                 return False
#             if [curPosX, curPosY] in obstacles:
#                 return False
#
#             com = command[i]
#             if com == 'U':
#                 curPosY += 1
#             elif com == 'R':
#                 curPosX += 1
#
#             if i + 1 >= n:
#                 i = 0
#             else:
#                 i += 1

""""
4. 覆盖

你有一块棋盘，棋盘上有一些格子已经坏掉了。你还有无穷块大小为1 * 2的多米诺骨牌，你想把这些骨牌不重叠地覆盖在完好的格子上，请找出你最多能在棋盘上放多少块骨牌？这些骨牌可以横着或者竖着放。

 

输入：n, m代表棋盘的大小；broken是一个b * 2的二维数组，其中每个元素代表棋盘上每一个坏掉的格子的位置。

输出：一个整数，代表最多能在棋盘上放的骨牌数。

 

示例 1：

输入：n = 2, m = 3, broken = [[1, 0], [1, 1]]
输出：2
解释：我们最多可以放两块骨牌：[[0, 0], [0, 1]]以及[[0, 2], [1, 2]]。（见下图）


 

示例 2：

输入：n = 3, m = 3, broken = []
输出：4
解释：下图是其中一种可行的摆放方式


 

限制：

1 <= n <= 8
1 <= m <= 8
0 <= b <= n * m
"""


# class Solution(object):
#     def domino(self, n, m, broken):
#         """
#         :type n: int
#         :type m: int
#         :type broken: List[List[int]]
#         :rtype: int
#         """

""""
5. 发 LeetCoin

力扣决定给一个刷题团队发LeetCoin作为奖励。同时，为了监控给大家发了多少LeetCoin，力扣有时候也会进行查询。

 

该刷题团队的管理模式可以用一棵树表示：

团队只有一个负责人，编号为1。除了该负责人外，每个人有且仅有一个领导（负责人没有领导）；
不存在循环管理的情况，如A管理B，B管理C，C管理A。
 

力扣想进行的操作有以下三种：

给团队的一个成员（也可以是负责人）发一定数量的LeetCoin；
给团队的一个成员（也可以是负责人），以及他/她管理的所有人（即他/她的下属、他/她下属的下属，……），发一定数量的LeetCoin；
查询某一个成员（也可以是负责人），以及他/她管理的所有人被发到的LeetCoin之和。
 

输入：

N表示团队成员的个数（编号为1～N，负责人为1）；
leadership是大小为(N - 1) * 2的二维数组，其中每个元素[a, b]代表b是a的下属；
operations是一个长度为Q的二维数组，代表以时间排序的操作，格式如下：
operations[i][0] = 1: 代表第一种操作，operations[i][1]代表成员的编号，operations[i][2]代表LeetCoin的数量； *1
operations[i][0] = 2: 代表第二种操作，operations[i][1]代表成员的编号，operations[i][2]代表LeetCoin的数量； *n
operations[i][0] = 3: 代表第三种操作，operations[i][1]代表成员的编号；
输出：

返回一个数组，数组里是每次查询的返回值（发LeetCoin的操作不需要任何返回值）。由于发的LeetCoin很多，请把每次查询的结果模1e9+7 (1000000007)。

 

示例 1：

输入：N = 6, leadership = [[1, 2], [1, 6], [2, 3], [2, 5], [1, 4]], operations = [[1, 1, 500], [2, 2, 50], [3, 1], [2, 6, 15], [3, 1]]
输出：[650, 665]
解释：团队的管理关系见下图。
第一次查询时，每个成员得到的LeetCoin的数量分别为（按编号顺序）：500, 50, 50, 0, 50, 0;
第二次查询时，每个成员得到的LeetCoin的数量分别为（按编号顺序）：500, 50, 50, 0, 50, 15.

限制：

1 <= N <= 50000
1 <= Q <= 50000
operations[i][0] != 3 时，1 <= operations[i][2] <= 5000
"""


class TreeNode(object):
    def __init__(self, value):
        self.val = value
        self.next = None


class Solution(object):
    def bonus(self, n, leadership, operations):
        """
        :type n: int
        :type leadership: List[List[int]]
        :type operations: List[List[int]]
        :rtype: List[int]
        """
        if not operations or not n or not leadership:
            return None
        # 1. 建树结构，多一个下属，算钱的时候多一个，并存map
        totalCoin = 0
        treeMap = {}
        resList = []
        for i in leadership:
            if i[0] not in treeMap:
                treeMap[i[0]] = 2
            if i[1] not in treeMap:
                treeMap[i[1]] = 1
            treeMap[i[0]] += 1

        # 2. 定义3种操作
        for operation in operations:
            if operation[0] == 1:
                totalCoin += operation[2]
            elif operation[0] == 2:
                totalCoin += operation[2] * treeMap[operation[1]]
            elif operation[0] == 3:
                # 3. 这是个求和，每次使用操作3，往结果列表添加和
                resList.append(totalCoin)
        return resList


if __name__ == '__main__':
    x = [2,2,3]
    y = [3,2,1]
    # print(Solution().game(x, y))
    # x = [3,2,0,2]
    # print(Solution().fraction(x))
    command = "URRUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU"
    obstacles = [[4, 2]]
    x = 39999999
    y = 299999
    # print(Solution().robot(command, obstacles, x, y))
    n = 6
    leadership = [[1, 2], [1, 6], [2, 3], [2, 5], [1, 4]]
    operations = [[1, 1, 500], [2, 2, 50], [3, 1], [2, 6, 15], [3, 1]]
    print(Solution().bonus(n, leadership, operations))

    # mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
    # print(Solution().smallestCommonElement(mat))
    # blocks = [1,1,1,1]
    # split = 100
    # print(Solution().minBuildTime(blocks, split))
