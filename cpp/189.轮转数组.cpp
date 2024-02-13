/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include <list>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        return method3(nums, k);
    }

    // 翻转数组
    void method3(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    void reverse(vector<int>& nums, int left, int right)
    {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }

    // 稍微优雅一点的恐惧O(n)写法
    void method2(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> tmp(n, n);
        for (int i = 0; i < n; i++) {
            tmp[(i + k) % n] = nums[i];
        }
        nums.assign(tmp.begin(), tmp.end());
    }

    // 丑陋的直观写法
    void method1(vector<int>& nums, int k)
    {
        list<int> S;

        int n = nums.size();
        k     = k % n;

        for (auto i : nums) {
            S.push_back(i);
        }

        for (int i = k; i > 0; i--) {
            nums[i - 1] = S.back();
            S.pop_back();
        }

        for (int i = k; i < n; i++) {
            nums[i] = S.front();
            S.pop_front();
        }
    }
};
// @lc code=end
