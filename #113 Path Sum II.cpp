/**
 * 113. Path Sum II
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * Given a binary tree and a sum, find all root-to-leaf paths 
 * where each path's sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> ans;
        vector<int> cur;
        solution(root, sum, 0, ans, cur);
        return ans;
    }

    void solution(TreeNode* node, int sum, int current_sum, vector<vector<int>>& ans, vector<int> cur) 
    {
        if (node == NULL) {
            return;
        }
        current_sum += node->val;
        cur.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            if (current_sum == sum) {
                ans.push_back(cur);
                return;
            } else {
                return;
            }
        }
        solution(node->left, sum, current_sum, ans, cur);
        solution(node->right, sum, current_sum, ans, cur);
    }
};

