/**
 * 72. Edit Distance
 * https://leetcode.com/problems/edit-distance/description/
 *
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 *     1. Insert a character
 *     2. Delete a character
 *     3. Replace a character
 *
 * Example 1:
 *     Input: word1 = "horse", word2 = "ros"
 *     Output: 3
 *     Explanation: 
 *         horse -> rorse (replace 'h' with 'r')
 *         rorse -> rose (remove 'r')
 *         rose -> ros (remove 'e')
 *
 * Example 2:
 *     Input: word1 = "intention", word2 = "execution"
 *     Output: 5
 *     Explanation: 
 *         intention -> inention (remove 't')
 *         inention -> enention (replace 'i' with 'e')
 *         enention -> exention (replace 'n' with 'x')
 *         exention -> exection (replace 'n' with 'c')
 *         exection -> execution (insert 'u')
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        if (word1 == "") {
            return word2.length();
        } else if (word2 == "") {
            return word1.length();
        }
        return solution(word1, word2);
    }

    int solution(string& s1, string& s2)
    {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            res[i][0] = i;
        }
        for (int i = 1; i <= n; i++) {
            res[0][i] = i;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    res[i][j] = res[i - 1][j - 1];
                } else {
                    res[i][j] = min(res[i - 1][j - 1] + 1, min(res[i - 1][j] + 1, res[i][j - 1] + 1));
                }
                // cout << res[i][j] << " ";
            }
            // cout << endl;
        }
        return res[m][n];
    }
};

int main()
{
    Solution s;
    string word1 = "intention", word2 = "execution";
    cout << s.minDistance(word1, word2) << endl;
    return 0;
}

