#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第 N 个结点
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # 双指针
    def removeNthFromEnd(self, head: Optional[ListNode],
                         n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        first = head
        second = dummy
        for i in range(n):
            first = first.next
        while first:
            first = first.next
            second = second.next
        second.next = second.next.next
        return dummy.next

    # 栈
    def removeNthFromEnd2(self, head: Optional[ListNode],
                          n: int) -> Optional[ListNode]:
        stack = list()
        dummy = ListNode(0, head)
        cur = dummy
        while cur:
            stack.append(cur)
            cur = cur.next
        for i in range(n):
            stack.pop()
        pre = stack.pop()
        pre.next = pre.next.next
        return dummy.next

    # 遍历长度后，再算倒数第N个
    def removeNthFromEnd1(self, head: Optional[ListNode],
                          n: int) -> Optional[ListNode]:
        length = 0
        cur = head
        while cur:
            cur = cur.next
            length += 1
        if length == n:
            return head.next

        index = length - n
        cur = head
        pre = None
        while index > 0:
            pre = cur
            cur = cur.next
            index -= 1
        pre.next = cur.next
        return head


# @lc code=end
