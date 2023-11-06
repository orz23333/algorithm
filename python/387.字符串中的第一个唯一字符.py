#
# @lc app=leetcode.cn id=387 lang=python3
#
# [387] 字符串中的第一个唯一字符
#
import collections


# @lc code=start
class Solution:
    # hash表加队列
    def firstUniqChar(self, s: str) -> int:
        hashMap = dict()
        queue = collections.deque()
        for i, ch in enumerate(s):
            if ch not in hashMap:
                hashMap[ch] = i
                queue.append((ch, i))
            else:
                hashMap[ch] = -1
                while queue and hashMap[queue[0][0]] == -1:
                    queue.popleft()
        return -1 if not queue else queue[0][1]

    # hash存储频次
    def firstUniqChar1(self, s: str) -> int:
        hashset = dict()
        for i in s:
            count = hashset.get(i, 0)
            hashset[i] = count + 1

        for i, ch in enumerate(s):
            if hashset.get(ch) == 1:
                return i

        return -1


print(Solution().firstUniqChar("loveleetcode"))
# @lc code=end
