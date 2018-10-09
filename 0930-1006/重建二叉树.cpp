/**
 * 重建二叉树
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return build(preorder, inorder, 0, 0, preorder.size());
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root, int start, int end)
    {
        if (root >= preorder.size()) {
            return NULL;
        }
        TreeNode* t = new TreeNode(preorder[root]);
        for (int i = start; i < end; i++) {
            if (inorder[i] == preorder[root]) {
                if (start != i)
                    t->left = build(preorder, inorder, root + 1, start, i);
                if (i != end - 1)
                    t->right = build(preorder, inorder, root + i - start + 1, i + 1, end);
                break;
            }
        }
        return t;
    }
};
