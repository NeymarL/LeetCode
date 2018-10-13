/**
 * 20 Valid Parentheses
 * https://leetcode.com/problems/valid-parentheses/
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 *
 * An input string is valid if:
 *     1. Open brackets must be closed by the same type of brackets.
 *     2. Open brackets must be closed in the correct order.
 *
 * Note that an empty string is also considered valid.
 */

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        if (s.length() == 0) {
            return true;
        }
        stack<char> st;
        unordered_map<char, char> map;
        map['('] = ')'; map['{'] = '}'; map['['] = ']';
        for (auto c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty() || map[st.top()] != c) {
                    return false;
                }
                st.pop();
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};
