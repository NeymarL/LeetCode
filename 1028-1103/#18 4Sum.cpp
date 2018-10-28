/**
 * 18. 4 Sum
 * https://leetcode.com/problems/4sum/
 * 
 * Given an array nums of n integers and an integer target, are there elements a, b, c, 
 * and d in nums such that a + b + c + d = target? Find all unique quadruplets in the 
 * array which gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * Example: Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *      A solution set is:
 *      [
 *          [-1,  0, 0, 1],
 *          [-2, -1, 1, 2],
 *          [-2,  0, 0, 2]
 *      ]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            bool skip = false;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == nums[j - 1] && skip) {
                    continue;
                }
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    if (nums[i] + nums[j] + nums[l] + nums[r] == target) {
                        vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(tmp);
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        r--;
                        l++;
                    } else if (nums[i] + nums[j] + nums[l] + nums[r] > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
                skip = true;
            }
        }
        return res;
    }
};
