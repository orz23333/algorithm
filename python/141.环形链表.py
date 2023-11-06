#
# @lc app=leetcode.cn id=141 lang=python3
#
# [141] 环形链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    # 快慢指针
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

    # hashSet
    def hasCycle1(self, head: Optional[ListNode]) -> bool:
        hashSet = set()
        cur = head
        while cur:
            if cur in hashSet:
                return True
            else:
                hashSet.add(cur)
            cur = cur.next
        return False


# @lc code=end
