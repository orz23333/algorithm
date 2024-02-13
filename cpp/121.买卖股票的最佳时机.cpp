/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        return dp(prices);
    }

    // 动态规划
    int dp(vector<int>& prices)
    {
        int n      = prices.size();
        int minNum = prices[0];
        vector<int> v_dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (prices[i] < minNum) {
                minNum = prices[i];
            }
            v_dp[i] = max(v_dp[i - 1], prices[i] - minNum);
        }
        return v_dp[n - 1];
    }

    // 贪婪算法
    int greedy(vector<int>& prices)
    {
        int minNum    = INT_MAX;
        int curProfix = 0;
        for (auto i : prices) {
            if (i < minNum) {
                minNum = i;
            }
            curProfix = max(curProfix, i - minNum);
        }
        return curProfix;
    }
};
// @lc code=end
