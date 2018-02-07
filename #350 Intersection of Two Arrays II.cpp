/**
 * 350. Intersection of Two Arrays II
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 *     Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 * Note:
 *     * Each element in the result should appear as many times as it shows in both arrays.
 *     * The result can be in any order.
 *
 * Follow up: 
 *     * What if the given array is already sorted? How would you optimize your algorithm?
 *     * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 *     * What if elements of nums2 are stored on disk, and the memory is limited such that 
 *       you cannot load all elements into the memory at once?
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n1 = (int)nums1.size(), n2 = (int)nums2.size();
    int i1 = 0, i2 = 0;
    vector<int> res;
    while(i1 < n1 && i2 < n2){
        if(nums1[i1] == nums2[i2]) {
            res.push_back(nums1[i1]);
            i1++;
            i2++;
        }
        else if(nums1[i1] > nums2[i2]){
            i2++;
        }
        else{
            i1++;
        }
    }
    return res;
}
