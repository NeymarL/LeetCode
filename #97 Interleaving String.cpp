/**
 * 97. Interleaving String
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * Example 1:
 *     Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 *     Output: true
 *     
 * Example 2:
 *     Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 *     Output: false
 *
 * F[i, j] = s3[0:i+j) is formed by s1[0:i) and s2[0:j)
 * F[0, 0, 0] = 1
 * F[i, j] = (F[i - 1, j] == 1 && s1[i - 1] == s3[i + j - 1]) ||
 *           (F[i, j - 1] == 1 && s2[j - 1] == s3[i + j - 1])
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) {
            return false;
        }
        vector<vector<char>> cache(n1 + 1, vector<char>(n2 + 1, 0));
        cache[0][0] = 1;
        bool temp = true;
        char val = temp ? 1 : 2;
        for (int j = 1; j <= n2; j++) {
            if (temp) {
                temp = s2.substr(0, j) == s3.substr(0, j);
            }
            cache[0][j] = temp ? 1 : 2;
        }
        temp = true;
        for (int i = 1; i <= n1; i++) {
            if (temp) {
                temp = s1.substr(0, i) == s3.substr(0, i);
            }
            cache[i][0] = temp ? 1 : 2;
        }
        if (solution(cache, n1, n2, s1, s2, s3) == 1) {
            return true;
        }
        return false;
    }

    char solution(vector<vector<char>>& cache, int i, int j, string& s1, string& s2, string& s3)
    {
        if (cache[i][j] != 0) {
            return cache[i][j];
        }
        cout << i << " " << j << endl;
        bool condition = (solution(cache, i - 1, j, s1, s2, s3) == 1 && s1[i - 1] == s3[i + j - 1]) ||
                         (solution(cache, i, j - 1, s1, s2, s3) == 1 && s2[j - 1] == s3[i + j - 1]);
        cache[i][j] = condition ? 1 : 2;
        return cache[i][j];
    }
};

int main()
{
    string s1 = "abaaacbacaab";
    string s2 = "bcccababccc";
    string s3 = "bcccabaaaaabccaccbacabb";
    Solution s;
    cout << s.isInterleave(s1, s2, s3) << endl;
    return 0;
}



