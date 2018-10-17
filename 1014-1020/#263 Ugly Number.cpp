/**
 * 263 Ugly Number
 * https://leetcode.com/problems/ugly-number/
 * 
 * Write a program to check whether a given number is an ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * 
 * Note:
 *      1 is typically treated as an ugly number.
 *      Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) 
    {
        if (num <= 0) {
            return false;
        }
        if (num <= 5) {
            return true;
        }
        while (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
            while (num % 2 == 0) {
                num /= 2;
            }
            while (num % 3 == 0) {
                num /= 3;
            }
            while (num % 5 == 0) {
                num /= 5;
            }
        }
        if (num == 1) {
            return true;
        }
        return false;
    }
};
