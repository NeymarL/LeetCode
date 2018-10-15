/**
 * 239. Sliding Window Maximum
 * https://leetcode.com/problems/sliding-window-maximum/
 * 
 * Given an array nums, there is a sliding window of size k which is moving from 
 * the very left of the array to the very right. You can only see the k numbers 
 * in the window. Each time the sliding window moves right by one position. 
 * Return the max sliding window.
 * 
 * Example:
 *     Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 *     Output: [3,3,5,5,6,7]
 * Explanation: 
 *     Window position                Max
 *     ---------------               -----
 *     [1  3  -1] -3  5  3  6  7      3
 *     1 [3  -1  -3] 5  3  6  7       3
 *     1  3 [-1  -3  5] 3  6  7       5
 *     1  3  -1 [-3  5  3] 6  7       5
 *     1  3  -1  -3 [5  3  6] 7       6
 *     1  3  -1  -3  5 [3  6  7]      7
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<pair<int, int>> dq;   // a better way is to store index rather than pair
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        }
        for (int i = 0; i < k; i++) {
            insert(dq, nums[i], i);
        }
        res.push_back(dq.back().first);
        for (int i = k; i < nums.size(); i++) {
            if (i - dq.back().second >= k) {
                dq.pop_back();
            }
            insert(dq, nums[i], i);
            res.push_back(dq.back().first);
        }
        return res;
    }

    void insert(deque<pair<int, int>>& dq, int num, int i)
    {
        if (dq.empty()) {
            dq.push_front(make_pair(num, i));
            return;
        }
        while (!dq.empty() && num > dq.front().first) {
            dq.pop_front();
        }
        dq.push_front(make_pair(num, i));
    }
};
