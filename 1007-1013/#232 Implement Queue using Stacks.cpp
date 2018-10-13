/**
 * 232 Implement Queue using Stacks
 * https://leetcode.com/problems/implement-queue-using-stacks/
 *
 * Implement the following operations of a queue using stacks.
 *     push(x) -- Push element x to the back of queue.
 *     pop() -- Removes the element from in front of queue.
 *     peek() -- Get the front element.
 *     empty() -- Return whether the queue is empty.
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        int tmp = output.top();
        output.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }

private:
    stack<int> input, output;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
