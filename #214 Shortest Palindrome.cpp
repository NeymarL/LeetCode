/**
 * 214. Shortest Palindrome
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. 
 * Find and return the shortest palindrome you can find by performing this transformation.
 *
 * Example 1:
 *     Input: "aacecaaa"
 *     Output: "aaacecaaa"
 *     
 * Example 2:
 *     Input: "abcd"
 *     Output: "dcbabcd"
 *
 * bbabcdaccadcba
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string shortestPalindrome(string s) 
{
    if (s.length() <= 1) {
        return s;
    }
    int n = s.length();
    string result = s;
    string rev(s);
    reverse(rev.begin(), rev.end());
    for (int i = 0; i < n; i++) {
        if (s.substr(0, n - i) == rev.substr(i))
            return rev.substr(0, i) + s;
    }
    return "";
}

int main()
{
    string s = "abcd";
    cout << shortestPalindrome(s) << endl;
    return 0;
}
