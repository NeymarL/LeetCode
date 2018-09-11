/**
 * 95. Unique Binary Search Trees II
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
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
    vector<TreeNode*> generateTrees(int n) 
    {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        return generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end)
    {
        vector<TreeNode*> list;

        if (start > end) {
            list.push_back(NULL);
            return list;
        }
        
        if (start == end) {
            list.push_back(new TreeNode(start));
            return list;
        }

        vector<TreeNode*> left;
        vector<TreeNode*> right;

        for (int i = start; i <= end; i++) {
            left = generate(start, i - 1);
            right = generate(i + 1, end);
            for (auto l: left) {
                for (auto r: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    list.push_back(root);
                }
            }
        }
        return list;
    }
};
