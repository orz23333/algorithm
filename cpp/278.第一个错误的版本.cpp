/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */
bool isBadVersion(int version);
// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        return method2(n);
    }

    // 二分查找
    int method2(int n)
    {
        int left  = 0;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                right = mid;
            }
            else {
                // 务必要+1，不然可能无限循环
                left = mid + 1;
            }
        }

        return left;
    }

    // 直接从小到大查询，O(n)
    int method1(int n)
    {
        for (int i = 0; i < n; i++) {
            if (isBadVersion(i)) {
                return i;
            }
        }
        return n;
    }
};
// @lc code=end
