/**
 * 228. Summary Ranges
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * Example 1:
 *     Input:  [0,1,2,4,5,7]
 *     Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 *
 * Example 2:
 *     Input:  [0,2,3,4,6,8,9]
 *     Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> ans;
        string s = "";
        for (int i = 0; i < nums.size(); i++) {
            if (s.length() == 0) {
                s += to_string(nums[i]);
            } else if (nums[i] - nums[i - 1] != 1) {
                if (stoi(s) != nums[i - 1])
                    s += "->" + to_string(nums[i - 1]);
                ans.push_back(s);
                s = to_string(nums[i]);
                if (i == nums.size() - 1) {
                    ans.push_back(s);
                    s = "";
                }
            } else if (i == nums.size() - 1) {
                s += "->" + to_string(nums[i]);
                ans.push_back(s);
                s = "";
            }
        }
        if (s.length() != 0) {
            ans.push_back(s);
        }
        return ans;
    }
};
