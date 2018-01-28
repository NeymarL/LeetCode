/**
 * 145. Binary Tree Postorder Traversal
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * For example:
 *     Given binary tree [1,null,2,3],
 *         1
 *          \
 *           2
 *          /
 *         3
 *     return [3,2,1].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal_withSet(TreeNode* root) 
{
    stack<TreeNode*> s;
    TreeNode* T = root;
    vector<int> res;
    set<TreeNode*> visited;
    while (T || !s.empty()) {
        while (T) {
            s.push(T);
            if (T->left) {
                T = T->left;
            } else {
                T = T->right;
            }
        }
        if (!s.empty()) {
            T = s.top();
            s.pop();
            if (T->right && visited.find(T->right) == visited.end()) {
                s.push(T);
                T = T->right;
                continue;
            } else {
                res.push_back(T->val);
                visited.insert(T);
                T = NULL;
            }
        }
    }
    return res;
}


vector<int> postorderTraversal(TreeNode* root) 
{
    stack<TreeNode*> s;
    TreeNode* T = root;
    TreeNode* pre = T;
    vector<int> res;
    while (T || !s.empty()) {
        while (T) {
            s.push(T);
            if (T->left) {
                T = T->left;
            } else {
                T = T->right;
            }
        }
        if (!s.empty()) {
            T = s.top();
            s.pop();
            if (T->right && T->right != pre) {
                s.push(T);
                T = T->right;
                continue;
            } else {
                res.push_back(T->val);
                pre = T;
                T = NULL;
            }
        }
    }
    return res;
}

vector<int> postorderTraversal_Easy(TreeNode* root) 
{
    stack<TreeNode*> s;
    TreeNode* T = root;
    vector<int> res;
    while (T || !s.empty()) {
        while (T) {
            s.push(T);
            res.insert(res.begin(), T->val);    // 先序遍历逆操作
            T = T->right;                       // 先序遍历逆操作
        }
        if (!s.empty()) {
            T = s.top();
            s.pop();
            T = T->left;                        // 先序遍历逆操作
        }
    }
    return res;
}

int main()
{
    return 0;
}
