/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
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
    bool isPalindrome(string s)
    {
        return method2(s);
    }

    /**
     * 双指针，但是跳过非字母数字
    */
    bool method2(string s)
    {
        int left  = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (left < right && tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    /**
     * 在入参上直接进行处理，并不是一个好办法，可以用另外一个空间进行存储
     */
    bool method1(string s)
    {
        for (auto i = s.begin(); i < s.end();) {
            if (!isalnum(*i)) {
                i = s.erase(i);
                continue;
            }
            i++;
        }

        int left  = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end
int main()
{
    (Solution()).isPalindrome("A man, a plan, a canal: Panama");
    cout << isalnum(':') << endl;
}