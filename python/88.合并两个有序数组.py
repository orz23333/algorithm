#
# @lc app=leetcode.cn id=88 lang=python3
#
# [88] 合并两个有序数组
#

# @lc code=start
class Solution:
    # 逆向双指针，不用多复制一个数组
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        p1 = m - 1
        p2 = n - 1
        tail = m + n - 1
        while p1 >= 0 or p2 >= 0:
            if p1 <= -1:
                nums1[tail] = nums2[p2]
                p2 -= 1
            elif p2 <= -1:
                nums1[tail] = nums1[p1]
                p1 -= 1
            elif nums1[p1] < nums2[p2]:
                nums1[tail] = nums2[p2]
                p2 -= 1
            else:
                nums1[tail] = nums1[p1]
                p1 -= 1
            tail -= 1


    # 双指针
    def merge2(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        sorted = [0] * (m + n)
        cur = 0
        p1 = 0
        p2 = 0
        while p1 < m or p2 < n:
            if p1 == m:
                sorted[cur] = nums2[p2]
                p2 += 1
            elif p2 == n:
                sorted[cur] = nums1[p1]
                p1 += 1
            elif nums1[p1] < nums2[p2]:
                sorted[cur] = nums1[p1]
                p1 += 1
            else:
                sorted[cur] = nums2[p2]
                p2 += 1
            cur += 1
        nums1[:] = sorted

    # 调用api，不满足m + n时间要求
    def merge1(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1[m:] = nums2
        nums1.sort()
# @lc code=end

