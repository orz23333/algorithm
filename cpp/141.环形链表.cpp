/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode* head) {
        return slow_fast_method(head);
    }

    // 快慢指针，追及问题
    bool slow_fast_method(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    // 通过hashmap的方式
    bool hash_method(ListNode* head)
    {
        unordered_set<ListNode*> set;
        while (head) {
            // 也可以用count方法计算数量来判断是否为空
            if (set.find(head) != set.end()) {
                return true;
            }
            set.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end
