/**
 * 78. Subsets
 * https://leetcode.com/problems/subsets/description/
 *
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *     Input: nums = [1,2,3]
 *     Output:
 *     [
 *       [3],
 *       [1],
 *       [2],
 *       [1,2,3],
 *       [1,3],
 *       [2,3],
 *       [1,2],
 *       []
 *     ]
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> result;
    if (nums.size() == 0) {
        return result;
    }
    result.push_back(vector<int>());
    auto ite = nums.begin();
    for (int i = 0; i < nums.size(); i++) {
        int n = result.size();
        for (int j = 0; j < n; j++) {
            vector<int> subset = result[j];
            subset.push_back(nums[i]);
            result.push_back(subset);
        }
    }
    return result;
}

