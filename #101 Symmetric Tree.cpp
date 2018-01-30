/**
 * 101. Symmetric Tree
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *         1
 *        / \
 *       2   2
 *      / \ / \
 *     3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
 *         1
 *        / \
 *       2   2
 *       \   \
 *       3    3
 *
 * Note: Bonus points if you could solve it both recursively and iteratively.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isEqual(TreeNode* left, TreeNode* right);

bool isSymmetric(TreeNode* root) 
{
    if (root == NULL) {
        return true;
    }
    return isEqual(root->left, root->right);
}

bool isEqual(TreeNode* left, TreeNode* right)
{
    if (left == NULL || right == NULL) {
        return left == right;
    }
    return (left->val == right->val) && isEqual(left->left, right->right) && isEqual(left->right, right->left);
}

int main()
{
    return 0;
}

