/**
 * 124 Binary Tree Maximum Path Sum
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * 
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from 
 * some starting node to any node in the tree along the parent-child 
 * connections. The path must contain at least one node and does not 
 * need to go through the root.
 * 
 * Example 1:
 *  Input: [1,2,3]
 *      1
 *     / \
 *    2   3
 *  Output: 6
 * 
 * Example 2:
 *  Input: [-10,9,20,null,null,15,7]
 *      -10
 *      / \
 *     9  20
 *       /  \
 *      15   7
 *  Output: 42
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) 
    {
        if (!root) {
            return 0;
        }
        int res = dfs(root);
        if (res > maxSum) {
            maxSum = res;
        }
        return maxSum;
    }

    int dfs(TreeNode* root)
    {
        int _max = 0;
        int sum = 0, res = 0;
        if (root->left) {
            res = dfs(root->left);
            _max = max(_max, res);
            sum += max(0, res);
        }
        if (root->right) {
            res = dfs(root->right);
            _max = max(_max, res);
            sum += max(0, res);
        }
        if (sum + root->val > maxSum) {
            maxSum = sum + root->val;
        }
        return _max + root->val;
    }

private:
    int maxSum = INT_MIN;
};
