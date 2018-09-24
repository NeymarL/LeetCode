/**
 * 856. Score of Parentheses
 * https://leetcode.com/problems/score-of-parentheses/
 *
 * Given a balanced parentheses string S, compute the score of the string based on the following rule:
 *     () has score 1
 *     AB has score A + B, where A and B are balanced parentheses strings.
 *     (A) has score 2 * A, where A is a balanced parentheses string.
 */

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) 
    {
        if (S.length() == 0) {
            return 0;
        }
        return (int)compute(S);
    }

    double compute(string s)
    {
        if (s.length() == 0) {
            return 0.5;
        }
        int i = 0, j = 0, cnt = 0, score = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                cnt++;
            } else if (s[i] == ')') {
                cnt--;
            }
            if (cnt == 0 && i != 0) {
                // cout << i << " " << j << " " << s.substr(j + 1, i - j - 1).length() << endl;
                score += compute(s.substr(j + 1, i - j - 1)) * 2;
                j = i + 1;
            }
            i++;
        }
        return score;
    }
};
