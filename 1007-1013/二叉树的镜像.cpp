/**
 * 二叉树的镜像
 * https://leetcode.com/problems/invert-binary-tree/
 *
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
 */

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
    TreeNode* invertTree(TreeNode* root) 
    {
        if (!root) {
            return NULL;
        }
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};
