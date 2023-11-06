#
# @lc app=leetcode.cn id=206 lang=python3
#
# [206] 反转链表
#

from typing import Optional


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # 递归
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newHead

    # 遍历
    def reverseList2(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre = None
        cur = head
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return pre

    # 栈
    def reverseList1(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        stack = list()
        while head:
            stack.append(head)
            head = head.next
        head = stack.pop()
        cur = head
        while stack:
            out = stack.pop()
            cur.next = out
            cur = out
        cur.next = None
        return head


# @lc code=end
