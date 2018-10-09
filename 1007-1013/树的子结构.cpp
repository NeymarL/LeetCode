/**
 * 树的子结构
 * https://leetcode.com/problems/subtree-of-another-tree/
 *
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if (!t || !s) {
            return false;
        }
        TreeNode* n;
        stack<TreeNode*> st;
        st.push(s);
        while (!st.empty()) {
            n = st.top();
            st.pop();
            if (n->val == t->val) {
                if (compare(n, t)) {
                    return true;
                }
            }
            if (n->left) {
                st.push(n->left);
            }
            if (n->right) {
                st.push(n->right);
            }
        }
        return false;
    }

    bool compare(TreeNode* s, TreeNode* t)
    {
        if (!t || !s) {
            if (s == NULL && t == NULL) {
                return true;
            }
            return false;
        }
        if (s->val == t->val) {
            return compare(s->left, t->left) && compare(s->right, t->right);
        }
        return false;
    }
};
