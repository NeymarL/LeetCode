/**
 * 整数中1出现的次数
 *
 * Given an integer n, count the total number of digit 1 appearing in 
 * all non-negative integers less than or equal to n.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) 
    {
        /**
         * The idea is to calculate occurrence of 1 on every digit. 
         * There are 3 scenarios, for example
         * 
         * if n = xyzdabc
         *
         * and we are considering the occurrence of one on thousand, it should be:
         *
         * (1) xyz * 1000                     if d == 0
         * (2) xyz * 1000 + abc + 1           if d == 1
         * (3) xyz * 1000 + 1000              if d > 1
         *
         * iterate through all digits and sum them all will give the final answer
         */
        if (n <= 0) {
            return 0;
        }
        int q = n, x = 1, digit = 0, res = 0;
        while (q > 0) {
            digit = q % 10;
            q /= 10;
            res += q * x;
            if (digit == 1) {
                res += n % x + 1;
            } else if (digit > 1) {
                res += x;
            }
            x *= 10;
        }
        return res;
    }
};
