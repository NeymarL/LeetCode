/**
 * 132. Palindrome Partitioning II
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * Example:
 *     Input: "aab"
 *     Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) 
    {
        int n = s.length();
        vector<int> F(n + 1);
        for (int i = 0; i < F.size(); i++) {
            F[i] = i - 1;
        }
        for (int i = 0; i < s.length(); i++) {
            // for odd palindrome
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) {
                F[i + j + 1] = min(F[i + j + 1], F[i - j] + 1);
            }
            // for even palindrome
            for (int j = 0; i - j + 1 >= 0 && i + j < n && s[i + j] == s[i - j + 1]; j++) {
                F[i + j + 1] = min(F[i + j + 1], F[i - j + 1] + 1);
            }
        }
        return F[n];
    }
};
