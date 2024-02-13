/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int slow = 1;
        int fast = 1;
        while (fast < n) {
            // 关键点：slow指示当前空着的格子，fast只是当前扫描的数字，如何fast不等于前一个
            // 值，说明出现了非重复值，那么可以把slow值置为fast，并且slow忘前移一位。
            // 此题的另一个关键点在于，把slow和fast置为1,。
            // 因为扫描到的第一个数肯定会占了0的位置。
            // 从而这个第一个数，可以作为基准值被fast-1引用，在下一次比较时实用。
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
// @lc code=end
