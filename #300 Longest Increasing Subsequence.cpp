/**
 * 300. Longest Increasing Subsequence
 *
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 * 
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18], The longest increasing subsequence is [2, 3, 7, 101], 
 * therefore the length is 4. Note that there may be more than one LIS combination, it is only 
 * necessary for you to return the length.
 * 
 * Your algorithm should run in O(n^2) complexity.
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * O(n^2) solution
 */
int lengthOfLIS(vector<int>& nums) 
{
    /**
     * Define F[i] = the length of the longest increasing subsequence
     * ending with nums[i]
     * So,
     *     F[0] = 1
     *     F[k] = max(F[i] + 1) for all i < k and nums[i] < nums[k]
     */
    if (nums.size() < 1) {
        return 0;
    }
    int max_len = 1;
    vector<int> F(nums.size(), 1);
    F[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                F[i] = max(F[i], F[j] + 1);
            }
        }
        max_len = max(max_len, F[i]);
    }
    return max_len;
}

/**
 * O(nlogn) solution
 */
int lengthOfLIS_NLogN(vector<int>& nums) 
{
    /**
     * `tails` is an array storing the smallest tail of all increasing 
     * subsequences with length `i+1` in `tails[i]`.
     *
     * For example, say we have nums = [4,5,6,3], then all the available increasing subsequences are:
     *     len = 1   :      [4], [5], [6], [3]   => tails[0] = 3
     *     len = 2   :      [4, 5], [5, 6]       => tails[1] = 5
     *     len = 3   :      [4, 5, 6]            => tails[2] = 6
     *
     * We can easily prove that `tails` is a increasing array. Therefore it is 
     * possible to do a binary search in tails array to find the one needs update.
     *
     * Each time we only do one of the two:
     *     1. if x is larger than all tails, append it, increase the size by 1
     *     2. if tails[i-1] < x <= tails[i], update tails[i]
     * Doing so will maintain the `tails` invariant. The the final answer is just the size.
     */
    if (nums.size() < 1) {
        return 0;
    }
    vector<int> tails;
    for (int num : nums) {
        if (tails.empty()) {
            tails.push_back(num);
            continue;
        }
        int l = 0, r = tails.size(), mid;
        while (l != r) {
            mid = (l + r) / 2;
            if (tails[mid] < num) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (r == tails.size()) {
            tails.push_back(num);
        }
        else {
            tails[r] = num;
        }
    }
    return tails.size();
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    cout << lengthOfLIS_NLogN(nums) << endl;
    return 0;
}
