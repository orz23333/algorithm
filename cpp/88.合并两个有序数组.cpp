/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        method2(nums1, m, nums2, n);
    }

    // 逆向双指针
    void method2(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int tail = m + n - 1;
        int p1   = m - 1;
        int p2   = n - 1;
        while (p1 >= 0 || p2 >= 0) {
            int cur = 0;
            if (p1 < 0) {
                cur = nums2[p2--];
            }
            else if (p2 < 0) {
                cur = nums1[p1--];
            }
            else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            }
            else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }

    // api法
    void method1(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};
// @lc code=end

int main()
{
    vector<int> v1 = {1, 2, 3, 0, 0, 0};
    vector<int> v2 = {2, 5, 6};
    (Solution()).merge(v1, 6, v2, 3);
}
