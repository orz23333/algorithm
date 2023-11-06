#
# @lc app=leetcode.cn id=155 lang=python3
#
# [155] 最小栈
#

# @lc code=start
class MinStack:
    #差值法
    def __init__(self):
        self.stack = list()
        self.min = 0

    def push(self, val: int) -> None:
        if not self.stack:
            self.stack.append(0)
            self.min = val
        else:
            diff = val - self.min
            self.stack.append(diff)
            if diff < 0:
                self.min = val

    def pop(self) -> None:
        diff = self.stack.pop()
        if diff < 0:
            top = self.min
            self.min = top - diff
        else:
            top = self.min + diff
        return top

    def top(self) -> int:
        return self.min if self.stack[-1] < 0 else self.min + self.stack[-1]

    def getMin(self) -> int:
        return self.min
'''
    # 辅助栈
    def __init__(self):
        self.stack = list()
        self.min_stack = [math.inf]

    def push(self, val: int) -> None:
        self.stack.append(val)
        self.min_stack.append(min(self.min_stack[-1], val))

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


    # 垃圾解法
    def __init__(self):
        self.min = float('inf')
        self.stack = list()

    def push(self, val: int) -> None:
        if val < self.min:
            self.min = val
        self.stack.append(val)

    def pop(self) -> None:
        ret = self.stack.pop()
        if ret == self.min and self.stack:
            self.min = min(self.stack)
        elif not self.stack:
            self.min = float('inf')

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min
'''

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

