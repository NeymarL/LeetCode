/**
 * 字符串的排列
 * https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 *
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
 * 则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> set;

    vector<string> Permutation(string str) 
    {
        vector<string> res;
        if (str == "") {
            return res;
        }
        string s = "";
        solution(s, str, res, set);
        return res;
    }

    void solution(string s, string unused, vector<string>& res, unordered_set<string>& set)
    {
        if (unused == "") {
            if (set.find(s) == set.end()) {
                set.insert(s);
                res.push_back(s);
            }
        }
        string tmp;
        for (int i = 0; i < unused.length(); i++) {
            tmp = unused;
            tmp.erase(i, 1);
            solution(s + unused[i], tmp, res, set);
        }
    }
};

int main()
{
    Solution s;
    string str = "aa";
    vector<string> v = s.Permutation(str);
    for (auto a: v) {
        cout << a << endl;
    }
    return 0;
}