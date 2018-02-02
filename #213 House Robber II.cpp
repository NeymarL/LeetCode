/**
 * 213. House Robber II
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * Note: This is an extension of #198 House Robber.
 * 
 * After robbing those houses on that street, the thief has found himself 
 * a new place for his thievery so that he will not get too much attention. 
 * This time, all houses at this place are arranged in a circle. That means 
 * the first house is the neighbor of the last one. Meanwhile, the security 
 * system for these houses remain the same as for those in the previous street.
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

int robber(vector<int>& nums, int start, int end) 
{
    int cur = 0, pre = 0, tmp = 0;
    for (int i = start + 1; i < end; i++) {
        tmp = max(pre + nums[i], cur);
        pre = cur;
        cur = tmp;
    }
    return cur;
}

/**
 * Suppose there are n houses, since house 0 and n - 1 are now neighbors, 
 * we cannot rob them together and thus the solution is now the maximum of
 *     1. Rob houses 0 to n - 2;
 *     2. Rob houses 1 to n - 1.
 */
int rob(vector<int>& nums)
{
    int n = nums.size(); 
    if (n < 2) return n ? nums[0] : 0;
    return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
}


int main()
{
    std::vector<int> v = {1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;
    cout << rob(v) << endl;
    return 0;
}