/**
 * 513. Find Bottom Left Tree Value
 * https://leetcode.com/problems/find-bottom-left-tree-value/
 *
 * Given a binary tree, find the leftmost value in the last row of the tree.
 *
 * Example: 
 *     Input:
 *               1
 *              / \
 *             2   3
 *            /   / \
 *           4   5   6
 *              /
 *             7
 *     Output: 7
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        unordered_map<TreeNode*, int> level;
        level[root] = 0;
        TreeNode* left = NULL;
        queue<TreeNode*> Q;
        Q.push(root);
        int lv = -1;

        while (!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            if (lv != level[node]) {
                left = node;
                lv = level[node];
            }
            if (node->left) {
                level[node->left] = level[node] + 1;
                Q.push(node->left);
            }
            if (node->right) {
                level[node->right] = level[node] + 1;
                Q.push(node->right);
            }
        }
        return left->val;
    }
};
