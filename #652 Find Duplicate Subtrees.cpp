/**
 * 652. Find Duplicate Subtrees
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, 
 * you only need to return the root node of any one of them.
 * 
 * Two trees are duplicate if they have the same structure with same node values.
 * Therefore, you need to return above trees' root in the form of a list.
 */

#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<string, int> count;
vector<TreeNode*> ans;

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
{
    collect(root);
    return ans;
}

string collect(TreeNode* root)
{
    if (root == NULL) {
        return string("#");
    }
    string serial = to_string(root->val) + "," + collect(root->left) + "," + collect(root->right);
    if (count.find(serial) == count.end()) {
        count[serial] = 1;
    } else {
        count[serial]++;
        if (count[serial] == 2) {
            ans.push_back(root);
        }
    }
    return serial;
}
