/**
 * 164. Maximum Gap
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * Given an unsorted array, find the maximum difference between the successive 
 * elements in its sorted form.
 *
 * Try to solve it in linear time/space.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * You may assume all elements in the array are non-negative integers and fit 
 * in the 32-bit signed integer range.
 */

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j);
int median3(vector<int>& nums, int left, int right);
void _quickSort(vector<int>& nums, int left, int right);
void quickSort(vector<int>& nums);

int maximumGap(vector<int>& nums) 
{
    if (nums.size() < 2) {
        return 0;
    }
    quickSort(nums);    // 练习了一下快排，基数排序更佳
    int maxGap = 0, gap = 0;
    for (int i = 1; i < nums.size(); i++) {
        gap = nums[i] - nums[i - 1];
        if (gap > maxGap) {
            maxGap = gap;
        }
    }
    return maxGap;
}

void quickSort(vector<int>& nums)
{
    _quickSort(nums, 0, nums.size() - 1);
}

void _quickSort(vector<int>& nums, int left, int right)
{
    if (left >= right) {
        return;
    }
    if (left + 1 == right) {
        if (nums[left] > nums[right]) {
            swap(nums, left, right);
            return;
        } else {
            return;
        }
    }
    int privot = median3(nums, left, right);
    int i = left, j = right - 1;
    while (1) {
        while (nums[++i] < privot);
        while (nums[--j] > privot);
        if (i < j) {
            swap(nums, i, j);
        } else {
            break;
        }
    }
    swap(nums, i, right - 1);
    _quickSort(nums, left, i - 1);
    _quickSort(nums, i + 1, right);
}

int median3(vector<int>& nums, int left, int right)
{
    int center = (left + right) / 2;
    // 目标: nums[left] <= nums[center] <= nums[right]
    if (nums[left] > nums[center]) {
        swap(nums, left, center);
    }
    if (nums[left] > nums[right]) {
        swap(nums, left, right);
    }
    if (nums[center] > nums[right]) {
        swap(nums, center, right);
    }
    // 将privot藏到右边，只需考虑 nums[left + 1], ...., nums[right - 2]
    swap(nums, center, right - 1);
    return nums[right - 1];
}

void swap(vector<int>& nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int main()
{
    std::vector<int> nums = {1, 1000000};
    quickSort(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    cout << maximumGap(nums) << endl;
    return 0;
}

