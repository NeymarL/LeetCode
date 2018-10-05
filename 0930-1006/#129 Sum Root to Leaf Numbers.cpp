/**
 * 129 Sum Root to Leaf Numbers
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note: A leaf is a node with no children.
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
    int sumNumbers(TreeNode* root) 
    {
        int sum = 0;
        vector<int> nums;
        preOrderTraversal(root, nums, sum);
        return sum;
    }

    void preOrderTraversal(TreeNode* t, vector<int>& nums, int& sum)
    {
        if (!t) {
            return;
        }
        nums.push_back(t->val);
        bool is_leaf = true;
        if (t->left) {
            is_leaf = false;
            preOrderTraversal(t->left, nums, sum);
        }
        if (t->right) {
            is_leaf = false;
            preOrderTraversal(t->right, nums, sum);
        }
        if (is_leaf) {
            int m = 0;
            for (int n: nums) {
                m = m * 10 + n;
            }
            sum += m;
            // cout << t->val << " " << m << " " << sum << endl;
        }
        nums.pop_back();
    }
};
