/**
 * 数组中只出现一次的数字
 * https://leetcode.com/problems/single-number-iii/
 * 
 * 一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
 * 
 * Example:
 *      Input:  [1,2,1,3,2,5]
 *      Output: [3,5]
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // First pass:
        // Get XOR of two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set(1) bit
        diff &= -diff;
        // Second pass:
        vector<int> res = {0, 0};
        for (int num: nums) {
            if ((num & diff) == 0) {    // the bit is not set
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }
        return res;
    }
};
