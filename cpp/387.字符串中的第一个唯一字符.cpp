/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        return method2(s);
    }

    /**
     * 使用hash表 + 队列 + 延迟删除
     */
    int method2(string s)
    {
        unordered_map<char, int> map;
        queue<pair<char, int>> Q;

        for (int i = 0; i < s.size(); i++) {
            if (!map.count(s[i])) {
                map[s[i]] = i;
                Q.emplace(s[i], i);
            }
            else {
                map[s[i]] = -1;
                while (!Q.empty() && map[Q.front().first] == -1) {
                    Q.pop();
                }
            }
        }

        return Q.empty() ? -1 : Q.front().second;
    }

    /**
     * 使用hash表
     */
    int method1(string s)
    {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
