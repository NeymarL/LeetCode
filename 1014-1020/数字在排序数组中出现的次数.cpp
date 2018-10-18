/**
 * 数字在排序数组中出现的次数
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 
 * Given an array of integers nums sorted in ascending order, 
 * find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 *      Input: nums = [5,7,7,8,8,10], target = 8
 *      Output: [3,4]
 * Example 2:
 *      Input: nums = [5,7,7,8,8,10], target = 6
 *      Output: [-1,-1]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res = {-1, -1};
        int idx = search(nums, target);
        if (idx == -1) {
            return res;
        }
        for (int i = idx; i >= 0 && nums[i] == target; i--) {
            res[0] = i;
        }
        for (int i = idx; i < nums.size() && nums[i] == target; i++) {
            res[1] = i;
        }
        return res;
    }

    int search(vector<int>& nums, int target)
    {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return -1;
    }
};

