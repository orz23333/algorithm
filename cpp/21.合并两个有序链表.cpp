/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        return dfs(list1, list2);
    }

    ListNode* dfs(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return nullptr;
        }

        ListNode* ret = nullptr;
        if (!list1 || !list2) {
            ret = !list1 ? list2 : list1;
            return ret;
        }

        if (list1->val > list2->val) {
            ret = list2;
            ret->next = dfs(list1, list2->next);
        } else {
            ret = list1;
            ret->next = dfs(list1->next, list2);
        }

        return ret;
    }

    ListNode* bfs(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* cur   = dummy;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        while (ptr1 && ptr2) {
            if (ptr1->val > ptr2->val) {
                cur->next = ptr2;
                ptr2      = ptr2->next;
            }
            else {
                cur->next = ptr1;
                ptr1      = ptr1->next;
            }
            cur = cur->next;
        }

        cur->next = ptr1 ? ptr1 : ptr2;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end
