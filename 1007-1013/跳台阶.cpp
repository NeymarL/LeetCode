/**
 * 跳台阶
 * https://leetcode.com/problems/climbing-stairs/
 *
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 *
 * 矩形覆盖（思路相同：斐波那次序列）
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> mem(n + 1, 0);
        return solution(0, n, mem);
    }

    int solution(int i, int n, vector<int>& mem)
    {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (mem[i] > 0) {
            return mem[i];
        }
        mem[i] = solution(i + 1, n, mem) + solution(i + 2, n, mem);
        return mem[i];
    }

    int jumpFloor(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};
