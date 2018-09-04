/**
 * 112. Path Sum
 * https://leetcode.com/problems/path-sum/description/
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf 
 * path such that adding up all the values along the path equals the given sum.
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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        return solution(root, sum, 0);
    }

    bool solution(TreeNode* node, int sum, int current_sum) 
    {
        if (node == NULL) {
            return false;
        }
        current_sum += node->val;
        if (node->left == NULL && node->right == NULL) {
            if (current_sum == sum) {
                return true;
            } else {
                return false;
            }
        }
        return solution(node->left, sum, current_sum) || solution(node->right, sum, current_sum);
    }
};
