/**
 * 437. Path Sum III
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must 
 * go downwards (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
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

class Solution {
public:
    int pathSum(TreeNode* root, int sum) 
    {
        int cnt = 0;
        stack<TreeNode*> s;
        TreeNode* node;
        node = root;
        while (node || !s.empty()) {
            while (node) {
                s.push(node);
                solution(node, sum, 0, cnt);
                node = node->left;
            }
            if (!s.empty()) {
                node = s.top();
                s.pop();
                node = node->right;
            }
        }
        return cnt;
    }

    void solution(TreeNode* node, int sum, int current_sum, int& cnt) 
    {
        if (node == NULL) {
            return;
        }
        current_sum += node->val;
        if (current_sum == sum) {
            cnt++;
        }
        solution(node->left, sum, current_sum, cnt);
        solution(node->right, sum, current_sum, cnt);
    }
};
