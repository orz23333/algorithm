#
# @lc app=leetcode.cn id=350 lang=python3
#
# [350] 两个数组的交集 II
#
from typing import List

# @lc code=start
class Solution:
    # 排序加双指针
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        len1 = len(nums1)
        len2 = len(nums2)
        index1 = 0
        index2 = 0
        intersection = list()
        while index1 < len1 and index2 < len2:
            if nums1[index1] > nums2[index2]:
                index2 += 1
            elif nums1[index1] < nums2[index2]:
                index1 += 1
            else:
                intersection.append(nums1[index1])
                index1 += 1
                index2 += 1
        return intersection

    # hash表
    def intersect2(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)
        
        m = collections.Counter()

        for i in nums1:
            m[i] += 1

        intersection = list()
        for i in nums2:
            if (counter := m.get(i, 0)) > 0:
                intersection.append(i)
                m[i] -= 1
                if m[i] == 0:
                    m.pop(i)
        return intersection

    # 暴力解法，非常垃圾
    def intersect1(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        s = s1 & s2
        countList1 = [0] * len(s)
        countList2 = [0] * len(s)
        for i, num1 in enumerate(s):
            for j in nums1:
                if j == num1:
                    countList1[i] += 1

        for i, num2 in enumerate(s):
            for j in nums2:
                if j == num2:
                    countList2[i] += 1

        maxCount = [0] * len(s)
        for i, _ in enumerate(maxCount):
            maxCount[i] = min(countList1[i], countList2[i])
        
        saveList = list()
        for i, num in enumerate(s):
            saveList.extend([num] * maxCount[i])

        return saveList


# Solution().intersect([4,9,5], [9,4,9,8,4])
# @lc code=end

