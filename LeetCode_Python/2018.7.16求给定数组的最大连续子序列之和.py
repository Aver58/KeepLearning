# 求给定数组的最大连续子序列之和
# 1.3 应用实例：
# 最大子列和问题
# 给定N个整数的序列{ A1, A2, …, AN}，
# 求函数 的最大值。
'''
input [1,-1,2,3,-5,6]
output：5
'''
import time

input = [1, -1, 2, 3, -5, 6, -10, 12, 33, 55]
# 第一种是把所有可能性都算一遍，出结果
def MaxSubSequenceNum_nXn(list):
    maxSum = 0
    length = len(list)
    for i in range(length):
        tempSum = 0
        for j in range(i, length):
            tempSum += list[j]
            if tempSum > maxSum:
                maxSum = tempSum
    # print("maxSum:%s" % maxSum)

# 第一种二分法，分而治之，先算出各自最大值，
# 再求出math.max(交界+最大值，最大值)
# def MaxSubSequenceNum_nXn(list):
#     def divive(list):
#         for i in range(0,len(list)/2):

# 在线处理法
def MaxSubSequenceNum_n(list):
    tempSum = 0
    maxSum = 0
    for i in range(len(list)):
        tempSum += list[i]
        if tempSum > maxSum:
            maxSum = tempSum
        elif tempSum < 0:
            tempSum = 0
    # print("maxSum:%s" % maxSum)


if __name__ == '__main__':
    print("time.time(): %f " % time.time())

    for i in range(100000):
        MaxSubSequenceNum_n(input)
    print("time.time(): %f " % time.time())

    for i in range(100000):
        MaxSubSequenceNum_nXn(input)
    print("time.time(): %f " % time.time())


