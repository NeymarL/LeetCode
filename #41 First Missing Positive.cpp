/**
 * 41. First Missing Positive
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * Given an unsorted integer array, find the smallest missing positive integer.
 * 
 * Example 1:
 *     Input: [1,2,0]
 *     Output: 3
 *     
 * Example 2:
 *     Input: [3,4,-1,1]
 *     Output: 2
 *     
 * Example 3:
 *     Input: [7,8,9,11,12]
 *     Output: 1
 *     
 * Note:
 *     Your algorithm should run in O(n) time and uses constant extra space.
 */

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int firstMissingPositive(vector<int>& nums)
{
    if (nums.size() == 0) {
        return 1;
    }
    for (int i = 0; i < nums.size(); i++) {
        int j = nums[i] - 1;
        // add condition `nums[j] != j + 1` to avoid endless loop
        while (j != i && j >= 0 && j < nums.size() && nums[j] != j + 1) {
            swap(nums, i, j);
            j = nums[i] - 1;
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        if (i + 1 != nums[i]) {
            return i + 1;
        }
    }
    return nums.size() + 1;
}
