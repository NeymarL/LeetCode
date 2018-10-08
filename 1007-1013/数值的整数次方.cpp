/**
 * 数值的整数次方
 * https://leetcode.com/problems/powx-n/
 *
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) 
    {
        double res = 1;
        if (x == 1.0) {
            return x;
        }
        long nn = n;
        if (n < 0) {
            x = 1 / x;
            nn = -nn;
        }
        while (nn != 0) {
            if (nn & 1 == 1) {
                res *= x;
            }
            x *= x;
            nn = nn >> 1;
        }
        return res;
    }
};
