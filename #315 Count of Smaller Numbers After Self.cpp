/**
 * 315. Count of Smaller Numbers After Self
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 *
 * You are given an integer array nums and you have to return a new counts array. 
 * The counts array has the property where counts[i] is the number of smaller 
 * elements to the right of nums[i].
 *
 * Example:
 *     Input: [5,2,6,1]
 *     Output: [2,1,1,0] 
 * Explanation:
 *     To the right of 5 there are 2 smaller elements (2 and 1).
 *     To the right of 2 there is only 1 smaller element (1).
 *     To the right of 6 there is 1 smaller element (1).
 *     To the right of 1 there is 0 smaller element.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> ind;
    vector<int> tmp_ind;

    vector<int> countSmaller(vector<int>& nums) 
    {
        ind = vector<int>(nums.size());
        tmp_ind = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ind[i] = i;
        }
        vector<int> tmp(nums.size());
        vector<int> counts(nums.size(), 0);
        mergeSort(nums, tmp, 0, nums.size() - 1, counts);
        // for (int i = 0; i < nums.size(); i++) {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        return counts;
    }

    void mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r, vector<int>& counts)
    {
        if (l >= r) {
            return;
        }
        int center = (l + r) / 2;
        mergeSort(nums, tmp, l, center, counts);
        mergeSort(nums, tmp, center + 1, r, counts);
        // merge
        int i = center, j = r, k = r;
        while (i >= l && j > center) {
            if (nums[i] > nums[j]) {
                counts[ind[i]] += j - center;
                tmp_ind[k] = ind[i];
                tmp[k--] = nums[i--];
            } else {
                tmp_ind[k] = ind[j];
                tmp[k--] = nums[j--];
            }
        }
        while (i >= l) {
            tmp_ind[k] = ind[i];
            tmp[k--] = nums[i--];
        }
        while (j > center) {
            tmp_ind[k] = ind[j];
            tmp[k--] = nums[j--];
        }
        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i];
            ind[i] = tmp_ind[i];
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> counts = s.countSmaller(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << counts[i] << " ";
    }
    cout << endl;
    return 0;
}
