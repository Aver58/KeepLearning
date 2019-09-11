class Solution(object):
    # 选择排序 n^2
    def ChooseSort(self, array):
        if array is None:
            return None
        comp = lambda x, y: x < y
        for i in range(len(array) - 1):
            minIndex = i
            # 找到最小索引，直接交换位置
            for j in range(i + 1, len(array)):
                if comp(array[j],array[minIndex]):
                    minIndex = j
            array[i], array[minIndex] = array[minIndex], array[i]
        return array

    # 冒泡排序 时间O(n^2) 空间O(1)
    def BubleSort(self, array):
        if array is None:
            return None
        n = len(array)
        # 外循环，逐个比对，小的往前挪
        for i in range(n):
            for j in range(i + 1, n):
                if array[j] < array[i]:
                    array[j], array[i] = array[i], array[j]
        # print(array)

    def BubleSortHigh(self, array):
        """高质量冒泡排序(搅拌排序)"""
        comp = lambda x, y: x > y
        items = array[:] # 深度复制
        n = len(items)
        for i in range(n - 1):
            swapped = False
            for j in range(i, n - 1 - i):
                if comp(items[j], items[j + 1]):
                    items[j], items[j + 1] = items[j + 1], items[j]
                    swapped = True
            if swapped:
                swapped = False
                for j in range(n - 2 - i, i, -1):
                    if comp(items[j - 1], items[j]):
                        items[j], items[j - 1] = items[j - 1], items[j]
                        swapped = True
            if not swapped:
                break
        return items

    def merge_sort(self, items, comp=lambda x, y: x <= y):
        """归并排序(分治法)"""
        if len(items) < 2:
            return items[:]
        mid = len(items) // 2
        left = self.merge_sort(items[:mid], comp)
        right = self.merge_sort(items[mid:], comp)
        return self.merge(left, right, comp)

    def merge(self, items1, items2, comp):
        """合并(将两个有序的列表合并成一个有序的列表)"""
        items = []
        index1, index2 = 0, 0
        while index1 < len(items1) and index2 < len(items2):
            if comp(items1[index1], items2[index2]):
                items.append(items1[index1])
                index1 += 1
            else:
                items.append(items2[index2])
                index2 += 1
        items += items1[index1:]
        items += items2[index2:]
        return items

    def seq_search(self,items, key):
        """顺序查找"""
        for index, item in enumerate(items):
            if item == key:
                return index
        return -1

    def bin_search(self,items, key):
        """折半查找"""
        start, end = 0, len(items) - 1
        while start <= end:
            mid = (start + end) // 2
            if key > items[mid]:
                start = mid + 1
            elif key < items[mid]:
                end = mid - 1
            else:
                return mid
        return -1

if __name__ == '__main__':
    list = [2, 3, 4, 5, 6, 7, 8, 9, 1, 0]
    print(Solution().BubleSortHigh(list))
