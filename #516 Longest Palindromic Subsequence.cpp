/**
 * 516. Longest Palindromic Subsequence
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * Given a string s, find the longest palindromic subsequence's length in s. 
 * You may assume that the maximum length of s is 1000.
 *
 * Example 1:
 *     Input: "bbbab"
 *     Output: 4
 *     One possible longest palindromic subsequence is "bbbb".
 *
 * Example 2:
 *     Input: "cbbd"
 *     Output: 2
 *     One possible longest palindromic subsequence is "bb".
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        if (s.length() == 0 || s.length() == 1) {
            return s.length();
        }
        string rev(s);
        reverse(rev.begin(), rev.end());
        return longestSubsequence(s, rev);
    }

    int longestSubsequence(string& a, string& b)
    {
        int n = a.length();
        vector<vector<int>> lcs(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i] == b[j]) {
                    if (i > 0 && j > 0) {
                        lcs[i][j] = lcs[i - 1][j - 1] + 1;
                    } else {
                        lcs[i][j] = 1;
                    }
                } else {
                    if (i > 0 && j > 0) {
                        lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                    } else if (i > 0) {
                        lcs[i][j] = lcs[i - 1][j];
                    } else if (j > 0) {
                        lcs[i][j] = lcs[i][j - 1];
                    }
                }
            }
        }
        return lcs[n - 1][n - 1];
    }
};
