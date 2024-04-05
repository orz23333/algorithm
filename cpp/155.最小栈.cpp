/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class MinStack {
public:
    /**
     * 利用辅助栈
    */
   stack<int> min_stack;
   stack<int> x_stack;

    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        min_stack.push(min(min_stack.top(), val));
        x_stack.push(val);
    }
    
    void pop() {
        min_stack.pop();
        x_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

