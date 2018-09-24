/**
 * 144. Binary Tree Preorder Traversal
 * https://leetcode.com/problems/binary-tree-preorder-traversal/
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode* t = S.top();
            S.pop();
            res.push_back(t->val);
            if (t->right) {
                S.push(t->right);
            }
            if (t->left) {
                S.push(t->left);
            }
        }
        return res;
    }
};
