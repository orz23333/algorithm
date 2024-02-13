/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <iostream>
#include <stack>

using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {}
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {}
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {}
};
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
    ListNode* reverseList(ListNode* head)
    {
        return m_stack(head);
    }

    ListNode* dfs(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = dfs(head->next);
        head->next->next  = head;
        head->next        = nullptr;
        return newHead;
    }

    ListNode* bfs(ListNode* head)
    {
        ListNode* pre  = nullptr;
        ListNode* next = nullptr;
        ListNode* cur  = head;
        while (cur) {
            next      = cur->next;
            cur->next = pre;
            pre       = cur;
            cur       = next;
        }
        return pre;
    }

    // c++的栈有tm的坑
    ListNode* m_stack(ListNode* head)
    {
        ListNode* cur = head;
        stack<ListNode*> S;
        while (cur) {
            S.push(cur);
            cur = cur->next;
        }

        ListNode* dummy = new ListNode(0);
        cur             = dummy;
        while (!S.empty()) {
            cur->next = S.top();
            cur       = cur->next;
            S.pop();
        }
        // 要置空，否则循环引用
        cur->next     = nullptr;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end
int main()
{
    ListNode l5(5);
    ListNode l4(4, &l5);
    ListNode l3(3, &l4);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);

    Solution S;
    ListNode* head = S.reverseList(&l1);
    cout << "ooooop.." << endl;
    return 0;
}