/**
 * 242. Valid Anagram
 * https://leetcode.com/problems/valid-anagram/
 * 
 * Given two strings s and t , write a function to determine if t is an anagram of s.
 * 
 * Example 1:
 *      Input: s = "anagram", t = "nagaram"
 *      Output: true
 * Example 2:
 *      Input: s = "rat", t = "car"
 *      Output: false
 * 
 * Note: You may assume the string contains only lowercase alphabets.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> map_s(128, 0), map_t(128, 0);
        for (int i = 0; i < s.length(); i++) {
            map_s[s[i]]++;
            map_t[t[i]]++;
        }
        for (auto c: s) {
            if (map_s[c] != map_t[c]) {
                return false;
            }
        }
        return true;
    }
};
