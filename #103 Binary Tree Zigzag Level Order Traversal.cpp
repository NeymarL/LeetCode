/**
 * 103. Binary Tree Zigzag Level Order Traversal
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. 
 * (ie, from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (!root) {
            return vector<vector<int>>();
        }
        unordered_map<TreeNode*, int> level;
        level[root] = 0;
        vector<vector<int>> ans;
        
        queue<TreeNode*> Q;
        Q.push(root);
        int lv = -1;

        while (!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            
            if (lv != level[node]) {
                if (lv != -1 && lv % 2 == 1) {
                    reverse(ans[lv], ans[lv].begin(), ans[lv].end());
                }
                lv = level[node];
                ans.push_back(vector<int>());
            }
            ans[lv].push_back(node->val);

            if (node->left) {
                level[node->left] = level[node] + 1;
                Q.push(node->left);
            }
            if (node->right) {
                level[node->right] = level[node] + 1;
                Q.push(node->right);
            }
        }

        if (lv % 2 == 1) {
            reverse(ans[lv], ans[lv].begin(), ans[lv].end());
        }
        return ans;
    }
};
