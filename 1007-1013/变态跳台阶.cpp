/**
 * 变态跳台阶
 * https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 *
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */

#include <iostream>
#include <vector>
#include <math>

using namespace std;

class Solution {
public:
    int jumpFloorII(int n) 
    {
        // int tmp = 1, ans = 0;
        // for (int i = 2; i <= n; i++) {
        //     // for (int j = 1; j < i; j++) {
        //     //     dp[i] += dp[j];
        //     // }
        //     ans = 2 * tmp;
        //     tmp = ans;
        // }
        return pow(2, n - 1);
    }
};
