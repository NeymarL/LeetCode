/**
 * 包含min函数的栈
 * https://leetcode.com/problems/min-stack/
 *
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        values.push(x);
        if (mini.empty() || x < getMin()) {
            mini.push(x);
        }
        else {
            mini.push(getMin());
        }
    }
    
    void pop() {
        values.pop();
        mini.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mini.top();
    }

private:
    stack<int> values, mini;
};
