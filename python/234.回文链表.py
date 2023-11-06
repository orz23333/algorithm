#
# @lc app=leetcode.cn id=234 lang=python3
#
# [234] 回文链表
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    #  快慢指针
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head:
            return True
        mid_node = self.find_mid_node(head)
        list2_head = self.reverse_list(mid_node.next)

        result = True
        node1 = head
        node2 = list2_head
        while result and node2:
            if node1.val != node2.val:
                result = False
            node1 = node1.next
            node2 = node2.next

        mid_node.next = self.reverse_list(list2_head)
        return result

    def reverse_list(self, head):
        pre = None
        cur = head
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return pre

    def find_mid_node(self, head):
        slow = head
        fast = head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        return slow

    # 借助栈
    def isPalindrome1(self, head: Optional[ListNode]) -> bool:
        stack = list()
        cur = head
        while cur:
            stack.append(cur)
            cur = cur.next
        n = len(stack)
        left = head
        for i in range(n // 2):
            right = stack.pop()
            if left.val != right.val:
                return False
            left = left.next
        return True


# @lc code=end
