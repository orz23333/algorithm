/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;
// @lc code=start
class Solution
{
public:
    /**
     * 构造（贪婪）
     */
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }

        int maxExec = max_element(freq.begin(),
                                  freq.end(),
                                  [](const auto& u, const auto& v) {
                                      return u.second < v.second;
                                  })
                          ->second;

        int maxCount = accumulate(
            freq.begin(), freq.end(), 0, [=](int acc, const auto& v) {
                return acc + (v.second == maxExec);
            });

        return max((maxExec - 1) * (n + 1) + maxCount, (int)(tasks.size()));
    }

    /**
     * 模拟
     */
    int leastInterval1(vector<char>& tasks, int n)
    {
        unordered_map<char, int> freq;
        unordered_map<char, int> nextTime;
        for (char ch : tasks) {
            freq[ch]++;
            nextTime[ch] = 1;
        }

        int time = 0;
        int len  = tasks.size();
        for (int i = 0; i < len; i++) {
            time++;

            int minNextTime = INT_MAX;
            for (auto [k, v] : nextTime) {
                if (freq[k] > 0) {
                    minNextTime = min(minNextTime, v);
                }
            }

            time = max(time, minNextTime);

            char best = -1;
            for (auto [k, v] : freq) {
                if (v > 0 && nextTime[k] <= time &&
                    (best == -1 || freq[k] > freq[best])) {
                    best = k;
                }
            }

            freq[best]--;
            nextTime[best] = time + n + 1;
        }

        return time;
    }
};
// @lc code=end
int main(int argc, char const* argv[])
{
    vector<char> task = {
        'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << (Solution()).leastInterval(task, 2) << endl;
    return 0;
}
