/**
 * 45. Jump Game II
 * https://leetcode.com/problems/jump-game-ii/
 * 
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 *      Input: [2,3,1,1,4]
 *      Output: 2
 *      Explanation: The minimum number of jumps to reach the last index is 2.
 *                  Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note: You can assume that you can always reach the last index.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if (nums.size() <= 1) {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        dp[1] = nums[0];
        if (dp[1] >= nums.size() - 1) {
            return 1;
        }
        for (int i = 2; i < dp.size(); i++) {
            int max_index = 0;
            for (int j = dp[i - 2]; j <= dp[i - 1]; j++) {
                max_index = max(max_index, j + nums[j]);
            }
            dp[i] = max_index;
            if (dp[i] >= nums.size() - 1) {
                return i;
            }
        }
        return nums.size() - 1;
    }
};
