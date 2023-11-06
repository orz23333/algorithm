#
# @lc app=leetcode.cn id=21 lang=python3
#
# [21] 合并两个有序链表
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # 递归
    def mergeTwoLists(self, list1: Optional[ListNode],
                      list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        elif not list2:
            return list1
        elif list1.val > list2.val:
            list2.next = self.mergeTwoLists(list2.next, list1)
            return list2
        else:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1

    # 迭代
    def mergeTwoLists1(self, list1: Optional[ListNode],
                       list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, None)
        cur = dummy
        while list1 and list2:
            if list1.val > list2.val:
                cur.next = list2
                list2 = list2.next
            else:
                cur.next = list1
                list1 = list1.next
            cur = cur.next

        cur.next = list1 if not list2 else list2

        return dummy.next


# @lc code=end
