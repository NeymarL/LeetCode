/**
 * 198. House Robber
 * https://leetcode.com/problems/house-robber/description/
 *
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed, the only constraint 
 * stopping you from robbing each of them is that adjacent houses have 
 * security system connected and it will automatically contact the police 
 * if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money 
 * of each house, determine the maximum amount of money you can rob tonight 
 * without alerting the police.
 *
 * Tag: Dynamic Programming
 */

#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int rob(vector<int>& nums) 
{
    /* d[i] means the most value that can be robbed before the ith store */
    vector<int> d(nums.size());
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    d[0] = nums[0];
    d[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        /* For each store, we have two choice: rob or not rob:
            (1) if robbing, d[i] = d[i-2] + nums[i], for stores robbed cannot be connected.
            (2) if not robbing, d[i] = d[i-1]; */
        d[i] = max(d[i - 2] + nums[i], d[i - 1]);
    }
    return d[nums.size() - 1];
}


int main()
{
    std::vector<int> v = {1,1,2,0};
    cout << rob(v) << endl;
    return 0;
}