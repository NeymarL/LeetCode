/**
 * 栈的压入、弹出序列
 * https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 *
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
 * 但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
    {
        stack<int> s;
        int j = 0, n = popV.size();
        s.push(pushV[j++]);
        for (int i = 0; i < n; i++) {
            while (popV[i] != s.top()) {
                if (j >= n) {
                    return false;
                }
                s.push(pushV[j++]);
            }
            s.pop();
        }
        return true;
    }
};
