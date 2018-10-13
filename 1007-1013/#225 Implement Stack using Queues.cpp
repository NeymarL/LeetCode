/**
 * 225 Implement Stack using Queues
 * https://leetcode.com/problems/implement-stack-using-queues/
 *
 * Implement the following operations of a stack using queues.
 *     push(x) -- Push element x onto stack.
 *     pop() -- Removes the element on top of the stack.
 *     top() -- Get the top element.
 *     empty() -- Return whether the stack is empty.
 */

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        first.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp;
        while (!first.empty()) {
            tmp = first.front();
            first.pop();
            if (first.empty()) {
                return tmp;
            }
            second.push(tmp);
        }
        while (!second.empty()) {
            tmp = second.front();
            second.pop();
            if (second.empty()) {
                return tmp;
            }
            first.push(tmp);
        }
    }
    
    /** Get the top element. */
    int top() {
        int tmp;
        while (!first.empty()) {
            tmp = first.front();
            first.pop();
            second.push(tmp);
            if (first.empty()) {
                return tmp;
            }
        }
        while (!second.empty()) {
            tmp = second.front();
            second.pop();
            first.push(tmp);
            if (second.empty()) {
                return tmp;
            }
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return first.empty() && second.empty();
    }

private:
    queue<int> first, second;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
