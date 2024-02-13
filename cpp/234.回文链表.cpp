/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* frontHead;

public:
    bool isPalindrome(ListNode* head)
    {
        // frontHead = head;
        // return dfs(head);
        return composited_method(head);
    }

    // 找到中间node反转，进行双指针判断，再还原链表
    bool composited_method(ListNode* head)
    {
        if (!head) {
            return true;
        }
        // 1.
        ListNode* front_mid = mid_node(head);
        ListNode* list2     = reverseList(front_mid->next);

        // 2.
        bool is_palindrome = true;
        ListNode* ptr1     = head;
        ListNode* ptr2     = list2;
        while (is_palindrome && ptr2) {
            is_palindrome = ptr1->val == ptr2->val ? is_palindrome : false;
            ptr1          = ptr1->next;
            ptr2          = ptr2->next;
        }

        // 3.
        front_mid->next = reverseList(list2);
        return is_palindrome;
    }

    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next  = head;
        head->next        = nullptr;
        return newHead;
    }



    ListNode* mid_node(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        // 这样写的查中间节点方式，返回的是比length / 2的中间值大1。
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 利用递归实现，类似于双指针，不过一个指针以全局变量的形式存在
    // 此处是利用了递归的性质：从最底层开始执行，实现的另一个指针的移动
    bool dfs(ListNode* head)
    {
        if (head) {
            if (!dfs(head->next)) {
                return false;
            }

            if (frontHead->val != head->val) {
                return false;
            }

            frontHead = frontHead->next;
        }
        return true;
    }

    // 将链表值存储在一个数组里去执行的方法略过
};
// @lc code=end
