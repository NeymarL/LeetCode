/**
 * 第一个只出现一次的字符
 * https://leetcode.com/problems/first-unique-character-in-a-string/
 * 
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 
 * 如果没有则返回 -1（需要区分大小写）.
 * 
 * Examples:
 *      s = "leetcode"
 *      return 0.
 * 
 *      s = "loveleetcode",
 *      return 2.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char, int> map;
        for (char c: s) {
            if (map.find(c) == map.end()) {
                map[c] = 1;
            } else {
                map[c]++;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }

    int firstUniqCharWithVector(string s) 
    {
        vector<int> map(127, 0);
        for (char c: s) {
            map[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
