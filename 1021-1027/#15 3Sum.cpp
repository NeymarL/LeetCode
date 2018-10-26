/**
 * 15. 3Sum
 * https://leetcode.com/problems/3sum/
 * 
 * Given an array nums of n integers, are there elements a, b, c in 
 * nums such that a + b + c = 0? Find all unique triplets in the 
 * array which gives the sum of zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 *      [-1, 0, 1],
 *      [-1, -1, 2]
 * ]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    res.push_back(tmp);
                    while (j < k && nums[k - 1] == nums[k]) k--;
                    while (j < k && nums[j + 1] == nums[j]) j++;
                    k--;
                    j++;
                }
            }
        }
        return res;
    }
};
