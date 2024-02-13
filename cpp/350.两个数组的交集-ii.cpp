/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        return method3(nums1, nums2);
    }

    // 排序 + 双指针
    vector<int> method3(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> ans;
        while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
            if (nums1[ptr1] < nums2[ptr2]) {
                ptr1++;
            }
            else if (nums1[ptr1] > nums2[ptr2]) {
                ptr2++;
            }
            else {
                ans.push_back(nums1[ptr1]);
                ptr1++;
                ptr2++;
            }
        }
        return ans;
    }

    // hash表计数，然后减数。当无法一次性读取所有数据时，可以使用这一方法分批次读取
    vector<int> method2(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() > nums2.size()) {
            return method2(nums2, nums1);
        }

        unordered_map<int, int> map;

        for (auto i : nums1) {
            map[i]++;
        }

        vector<int> ans;
        for (auto i : nums2) {
            if (map[i]) {
                ans.push_back(i);
                map[i]--;
            }
        }

        return ans;
    }

    // 暴力遍历，思路类似于回溯
    vector<int> method1(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() > nums2.size()) {
            return method2(nums2, nums1);
        }

        vector<int> ans;
        vector<bool> used(nums2.size(), false);

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == nums1[i] && !used[j]) {
                    ans.push_back(nums1[i]);
                    used[j] = true;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end