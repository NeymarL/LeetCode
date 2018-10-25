/**
 * 字符流中第一个不重复的字符
 * https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * 
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
 * 第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 * 
 * 输出描述: 如果当前字符流没有存在出现一次的字符，返回#字符。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    Solution(): s(""), table(128, 0) {}

  //Insert one char from stringstream
    void Insert(char ch)
    {
         s += ch;
         table[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for (auto c: s) {
            if (table[c] == 1) {
                return c;
            }
        }
        return '#';
    }

private:
    string s;
    vector<int> table;
};
