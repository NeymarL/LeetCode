/**
 * 连续子数组的最大和
 *
 * 给一个数组，返回它的最大连续子序列的和
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
    {
        int cur_sum = 0, max_sum = INT_MIN;
        for (int num: array) {
            cur_sum += num;
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
            }
            if (cur_sum < 0) {
                cur_sum = 0;
            }
        }
        return max_sum;
    }
};
