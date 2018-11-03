/**
 * 3. Longest Substring Without Repeating Characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 *      Input: "abcabcbb"
 *      Output: 3 
 *      Explanation: The answer is "abc", with the length of 3. 
 * 
 * Example 2:
 *      Input: "bbbbb"
 *      Output: 1
 *      Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 *      Input: "pwwkew"
 *      Output: 3
 *      Explanation: The answer is "wke", with the length of 3. 
 *              Note that the answer must be a substring, "pwke" is a
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> map(128, -1);
        string sub = "";
        int maxLength = 0;
        int start = 0;
        for (auto c: s) {
            if (map[c] >= start) {
                start = map[c] + 1;
            }
            sub += c;
            map[c] = sub.length() - 1;
            maxLength = max(maxLength, (int)sub.length() - start);
        }
        return maxLength;
    }
};
