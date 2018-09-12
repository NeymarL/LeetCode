/**
 * 115. Distinct Subsequences
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original string by deleting 
 * some (can be none) of the characters without disturbing the relative positions of the remaining 
 * characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Example 1:
 *     Input: S = "rabbbit", T = "rabbit"
 *     Output: 3
 * Explanation:
 *     As shown below, there are 3 ways you can generate "rabbit" from S. (The caret symbol ^ means the chosen letters)
 *     rabbbit
 *     ^^^^ ^^
 *     rabbbit
 *     ^^ ^^^^
 *     rabbbit
 *     ^^^ ^^^
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) 
    {
        return longestCommonSubsequence(s, t);
    }

    int longestCommonSubsequence(string& s, string& t)
    {
        int m = s.length(), n = t.length();
        vector<vector<int>> lcs(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> mark(m + 1, vector<int>(n + 1, -1)); // 0: <-, 1: ^, 2: \ .
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                    mark[i][j] = 2;
                } else {
                    if (lcs[i - 1][j] > lcs[i][j - 1]) {
                        lcs[i][j] = lcs[i - 1][j];
                        mark[i][j] = 1;
                    } else {
                        lcs[i][j] = lcs[i][j - 1];
                        mark[i][j] = 0;
                    }
                }
            }
        }
        if (lcs[m][n] != n) {
            return 0;
        }
        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << lcs[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));
        return trackSolution(lcs, mark, cache, m, n);
    }

    int trackSolution(vector<vector<int>>& lcs, vector<vector<int>>& mark, vector<vector<int>>& cache, int i, int j)
    {
        if (cache[i][j] != -1) {
            return cache[i][j];
        }
        int ans = 0;
        if (mark[i][j] == -1 || i == 0 || j == 0) {
            return 1;
        }
        if (mark[i][j] == 2) {
            if (lcs[i][j] == lcs[i - 1][j]) {
                ans += trackSolution(lcs, mark, cache, i - 1, j);
            }
            if (lcs[i][j] == lcs[i][j - 1]) {
                ans += trackSolution(lcs, mark, cache, i, j - 1);
            }
            ans += trackSolution(lcs, mark, cache, i - 1, j - 1);
        } else {
            if (mark[i][j] == 0) {
                ans += trackSolution(lcs, mark, cache, i, j -1);
            } else {
                ans += trackSolution(lcs, mark, cache, i - 1, j);
            }
        }
        cache[i][j] = ans;
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "babgbag", t = "bag";
    cout << sol.numDistinct(s, t) << endl;
    return 0;
}
