/**
 * 698. Partition to K Equal Sum Subsets
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * Given an array of integers nums and a positive integer k, find whether it's possible 
 * to divide this array into k non-empty subsets whose sums are all equal.
 *
 * Example 1:
 *     Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 *     Output: True
 *     Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 *
 * Note:
 *     1 <= k <= len(nums) <= 16.
 *     0 < nums[i] < 10000.
 *
 * 计算子列和是否等于特定值可以用DFS
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& nums, vector<int>& visited, int start, int k, int cur_sum, int target)
{
    if (k == 1) {
        return true;
    }
    if (cur_sum == target) {
        return find(nums, visited, 0, k - 1, 0, target);
    }
    if (cur_sum > target) {
        return false;
    }
    for (int i = start; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = 1;
            if (find(nums, visited, i + 1, k, cur_sum + nums[i], target)) {
                return true;
            }
            visited[i] = 0;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) 
{
    int sum = 0;
    for (int num: nums) {
        sum += num;
    }
    if (sum % k != 0) {
        return false;
    }
    if (k == 1) {
        return true;
    }
    int target = sum / k;
    vector<int> visited(nums.size(), 0);
    return find(nums, visited, 0, k, 0, target);
}

int main()
{
    std::vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    cout << canPartitionKSubsets(nums, 4) << endl;
    return 0;
}
