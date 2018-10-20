/**
 * 翻转单词顺序列
 * https://leetcode.com/problems/reverse-words-in-a-string/
 * 
 * Given an input string, reverse the string word by word.
 * 
 * Example:  
 *      Input: "the sky is blue",
 *      Output: "blue is sky the".
 * 
 * Note:
 *      A word is defined as a sequence of non-space characters.
 *      Input string may contain leading or trailing spaces. However, 
 *          your reversed string should not contain leading or trailing spaces.
 *      You need to reduce multiple spaces between two words to a single space in the reversed string.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string& str) 
    {
        vector<string> words;
        int last_space = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                if (i > 0 && str[i - 1] == ' ') {
                    last_space = i + 1;
                    continue;
                }
                if (i == 0) {
                    last_space = i + 1;
                    continue;
                }
                words.push_back(str.substr(last_space, i - last_space));
                last_space = i + 1;
            }
            else if (i == str.length() - 1) {
                words.push_back(str.substr(last_space, i - last_space + 1));
            }
        }
        reverse(words.begin(), words.end());
        str = "";
        for (int i = 0; i < words.size(); i++) {
            str += words[i];
            if (i != words.size() - 1) {
                str += ' ';
            }
        }
        return str;
    }
};
