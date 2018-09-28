/**
 * 515. Find Largest Value in Each Tree Row
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/
 *
 * You need to find the largest value in each row of a binary tree.
 *
 * Example:
 * Input: 
 *         1
 *        / \
 *       3   2
 *      / \   \  
 *     5   3   9 
 * Output: [1, 3, 9]
 */

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        if (root == NULL) {
            return vector<int>();
        }
        vector<int> result;
        queue<TreeNode*> Q;
        Q.push(root);
        int level_max = root->val, last_lv = 0;
        unordered_map<TreeNode*, int> level;
        level[root] = 0;
        
        while (!Q.empty()) {
            TreeNode* t = Q.front();
            Q.pop();
            if (last_lv != level[t]) {
                last_lv = level[t];
                result.push_back(level_max);
                level_max = t->val;
            } else {
                if (t->val > level_max) {
                    level_max = t->val;
                }
            }
            if (t->left) {
                Q.push(t->left);
                level[t->left] = level[t] + 1;
            }
            if (t->right) {
                Q.push(t->right);
                level[t->right] = level[t] + 1;
            }
        }
        result.push_back(level_max);
        return result;
    }
};
