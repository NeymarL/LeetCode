/**
 * 449. Serialize and Deserialize BST
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * Serialization is the process of converting a data structure or object into a sequence 
 * of bits so that it can be stored in a file or memory buffer, or transmitted across a 
 * network connection link to be reconstructed later in the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary search tree. There is no restriction 
 * on how your serialization/deserialization algorithm should work. You just need to ensure that a 
 * binary search tree can be serialized to a string and this string can be deserialized to the original 
 * tree structure.
 * 
 * The encoded string should be as compact as possible.
 * 
 * Note: Do not use class member/global/static variables to store states. Your serialize and 
 * deserialize algorithms should be stateless.
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "#";
        }
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        TreeNode* root = build_tree(ss);
        return root;
    }

    TreeNode* build_tree(stringstream& ss) {
        string val;
        if (getline(ss, val, ' ')) {
            if (val == "#") {
                return NULL;
            }
            TreeNode* node = new TreeNode(stoi(val));
            node->left = build_tree(ss);
            node->right = build_tree(ss);
            return node;
        }
        return NULL;
    }
};



