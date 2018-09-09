/**
 * 32. Longest Valid Parentheses
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * Given a string containing just the characters '(' and ')', find the 
 * length of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *     Input: "(()"
 *     Output: 2
 *     Explanation: The longest valid parentheses substring is "()"
 *     
 * Example 2:
 *     Input: ")()())"
 *     Output: 4
 *     Explanation: The longest valid parentheses substring is "()()"
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n <= 1) {
            return 0;
        }
        vector<int> lvp(n, 0);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    lvp[i] = (i - 2 >= 0 ? lvp[i - 2]: 0) + 2;
                } else {
                    if (lvp[i - 1] == 0) {
                        lvp[i] = 0;
                    } else {
                        int j = i - 1 - lvp[i - 1];
                        if (j >= 0 && s[j] == '(') {
                            lvp[i] = lvp[i - 1] + 2;
                            if (j - 1 >= 0) {
                                lvp[i] += lvp[j - 1];
                            }
                        }
                    }
                }
            }
            ans = max(ans, lvp[i]);
        }
        return ans;
    }
};
