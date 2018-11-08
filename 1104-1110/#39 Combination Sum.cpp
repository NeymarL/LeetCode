/**
 * 39. Combination Sum
 * https://leetcode.com/problems/combination-sum/
 * 
 * Given a set of candidate numbers (candidates) (without duplicates) 
 * and a target number (target), find all unique combinations in candidates 
 * where the candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of times.
 * 
 * Note:
 *      All numbers (including target) will be positive integers.
 *      The solution set must not contain duplicate combinations.
 * 
 * Example 1:
 *      Input: candidates = [2,3,6,7], target = 7,
 *      A solution set is:
 *      [
 *          [7],
 *          [2,2,3]
 *      ]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }

    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
