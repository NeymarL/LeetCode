/**
 * 476. Number Complement
 * https://leetcode.com/problems/number-complement/
 *
 * Given a positive integer, output its complement number. 
 * The complement strategy is to flip the bits of its binary representation.
 *
 * Note:
 *     The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 *     You could assume no leading zero bit in the integer’s binary representation.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findComplement(int num) 
    {
        bool start = false;
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            if ((num & (1 << i)) != 0) {
                if (!start) {
                    start = true;
                }
            } else if (start) {
                result |= 1 << i;
            }
        }
        return result;
    }
};
