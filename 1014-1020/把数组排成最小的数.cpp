/**
 * 把数组排成最小的数
 * https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct comp {
    bool operator() (const int a, const int b) const {
        string sa = to_string(a), sb = to_string(b);
        int i;
        for (i = 0; i < min(sa.length(), sb.length()); i++) {
            if (sa[i] < sb[i]) {
                return false;
            } else if (sa[i] > sb[i]) {
                return true;
            }
        }
        while (i < sa.length()) {
            if (sa[i] < sb[0]) {
                return false;
            } else if (sa[i] > sb[0]) {
                return true;
            }
            i++;
        }
        while (i < sb.length()) {
            if (sb[i] < sa[0]) {
                return true;
            } else if (sb[i] > sa[0]) {
                return false;
            }
            i++;
        }
        return true;
    }
};

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) 
    {
        priority_queue<int, vector<int>, comp> pq;
        for (auto num: numbers) {
            pq.push(num);
        }
        string res = "";
        while (!pq.empty()) {
            res += to_string(pq.top());
            pq.pop();
        }
        return res;
    }
};
