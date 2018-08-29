/**
 * 5. Longest Palindromic Substring
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * Given a string s, find the longest palindromic substring in s. 
 * You may assume that the maximum length of s is 1000.
 *
 * Example 1:
 *     Input: "babad"
 *     Output: "bab"
 *     Note: "aba" is also a valid answer.
 *     
 * Example 2:
 *     Input: "cbbd"
 *     Output: "bb"
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int check_palindrome(vector<vector<int>>& is_palindrome, string& s, int i, int j);

string longestPalindrome(string s) 
{
    if (s.length() <= 1) {
        return s;
    }
    string result(1, s[0]);
    vector<vector<int>> is_palindrome(s.length(), vector<int>(s.length(), -1));
    for (int i = 0; i < s.length(); i++) {
        is_palindrome[i][i] = 2;
    }
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            is_palindrome[i][j] = check_palindrome(is_palindrome, s, i, j);
            if (is_palindrome[i][j]) {
                if (j - i + 1 > result.length()) {
                    result = s.substr(i, j - i + 1);
                }
            }
        }
    }
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            cout << is_palindrome[i][j] << " ";
        }
        cout << endl;
    }
    return result;
}

int check_palindrome(vector<vector<int>>& is_palindrome, string& s, int i, int j)
{
    if (is_palindrome[i][j] >= 0) {
        return is_palindrome[i][j];
    }
    if (j - 1 >= 0) {
        if (is_palindrome[i][j - 1] == -1) {
            is_palindrome[i][j - 1] = check_palindrome(is_palindrome, s, i, j - 1);
        }
        if (is_palindrome[i][j - 1] == 2 && s[i] == s[j]) {
            return 2;
        }
    }
    if (j - 1 >= 0 && i + 1 < s.length()) {
        if (is_palindrome[i+1][j-1] == -1) {
            is_palindrome[i+1][j-1] = check_palindrome(is_palindrome, s, i + 1, j - 1);
        }
        if (is_palindrome[i+1][j-1] > 0 && s[i] == s[j]) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    string s = "cbbd";
    cout << longestPalindrome(s) << endl;
    return 0;
}
