/**
 * 107. Binary Tree Level Order Traversal II
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 * (ie, from left to right, level by level from leaf to root).
 * 
 * For example:
 *     Given binary tree [3,9,20,null,null,15,7],
 *        3
 *       / \
 *      9  20
 *        /  \
 *      15   7
 *
 *     return its bottom-up level order traversal as:
 *     [
 *       [15,7],
 *       [9,20],
 *       [3]
 *     ]
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
    vector<vector<int>> result;
    queue<TreeNode*> Q;
    if (root == NULL) {
        return result;
    }
    Q.push(root);
    int childs = 1, next_lv_childs = 0;
    vector<int> res;
    while (!Q.empty()) {
        TreeNode* node = Q.front();
        Q.pop();
        childs--;
        res.push_back(node->val);
        if (node->left) {
            Q.push(node->left);
            next_lv_childs++;
        }
        if (node->right) {
            Q.push(node->right);
            next_lv_childs++;
        }
        if (childs == 0) {
            result.insert(result.begin(), res);
            res.clear();
            childs = next_lv_childs;
            next_lv_childs = 0;
        }
    }
    return result;
}

