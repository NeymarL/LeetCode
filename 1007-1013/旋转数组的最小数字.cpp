/**
 * 旋转数组的最小数字
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
 * 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }
        int left = 0, right = nums.size() - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (nums[mid] >= nums[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return min(nums[left], nums[right]);
    }
};
