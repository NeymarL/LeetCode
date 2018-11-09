/**
 * 44. Wildcard Matching
 * https://leetcode.com/problems/wildcard-matching/
 * 
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 *      s could be empty and contains only lowercase letters a-z.
 *      p could be empty and contains only lowercase letters a-z, and characters like ? or *.
 * 
 * Example 1:
 * Input:
 *      s = "adceb"
 *      p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
 * 
 * Example 2:
 * Input:
 *      s = "acdcb"
 *      p = "a*c?b"
 * Output: false
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string str, string pattern) 
    {
        const char *s = str.c_str(), *p = pattern.c_str();
        const char* star = NULL;
        const char* ss = s;
        while (*s) {
            // advancing both pointers when (both characters match) or ('?' found in pattern)
            // note that *p will not advance beyond its length 
            if ((*p == '?') || (*p == *s)) {
                s++;
                p++;
                continue;
            } 

            //  * found in pattern, track index of *, only advancing pattern pointer 
            if (*p == '*') {
                star = p++;
                ss = s;
                continue;
            } 

            // current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            // only advancing pattern pointer
            if (star) { 
                p = star + 1; 
                s = ++ss;
                continue;
            } 

            // current pattern pointer is not star, last patter pointer was not *
            // characters do not match
            return false;
        }

        // check for remaining characters in pattern
        while (*p == '*') {
            p++;
        }

        return !*p;  
    }
};
