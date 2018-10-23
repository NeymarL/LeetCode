/**
 * 不用加减乘除做加法
 * 
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int res = 0;
        int carry = 0;
        int i = 0;
        while ((num1 || num2 || carry) && i < 32) {
            // cout << num1 << " " << num2 << " " << carry << " ";
            res |= ((((num1 ^ num2) ^ carry)) & 1) << i;
            // cout << res << endl;
            if (((num1 & 1) && (num2 & 1)) ||
                ((num1 & 1) && (carry & 1)) ||
                ((num2 & 1) && (carry & 1))) {
                carry = 1;
            } else {
                carry = 0;
            }
            num1 >>= 1;
            num2 >>= 1;
            i++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.Add(-1, -1) << endl;
    return 0;
}
