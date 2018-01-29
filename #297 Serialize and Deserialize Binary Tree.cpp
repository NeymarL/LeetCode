/**
 * 297. Serialize and Deserialize Binary Tree
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * Serialization is the process of converting a data structure or object into a sequence of bits 
 * so that it can be stored in a file or memory buffer, or transmitted across a network connection 
 * link to be reconstructed later in the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how 
 * your serialization/deserialization algorithm should work. You just need to ensure that a binary 
 * tree can be serialized to a string and this string can be deserialized to the original tree structure.
 * 
 * For example, you may serialize the following tree
 *
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 *   
 *  as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do 
 *  not necessarily need to follow this format, so please be creative and come up with different 
 *  approaches yourself.
 *
 * Note: Do not use class member/global/static variables to store states. Your serialize and 
 * deserialize algorithms should be stateless.
 */

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Encodes a tree to a single string.
// 层序遍历
string serialize(TreeNode* root) 
{
    queue<TreeNode*> Q;
    TreeNode* T = root;
    string code;
    Q.push(T);
    while (!Q.empty()) {
        T = Q.front();
        Q.pop();
        if (T) {
            code += std::to_string(T->val);
            code += ',';
            Q.push(T->left);
            Q.push(T->right);
        }
        else {
            code += "null,";
        }
    }
    if (root == NULL) {
        code = "";
    }
    return code;
}

int read_node(string data, int& index, bool& is_null);

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) 
{
    if (data.length() == 0) {
        return NULL;
    }
    int index = 0, val = 0;
    bool is_null = false;
    TreeNode *root, *T, *parent;
    queue<TreeNode*> Q;
    val = read_node(data, index, is_null);
    root = new TreeNode(val);
    parent = root;
    Q.push(root);
    while (!Q.empty()) {
        parent  = Q.front();
        Q.pop();
        if (index < data.length() - 1) {
            val = read_node(data, index, is_null);
            if (!is_null) {
                T = new TreeNode(val);
                parent->left = T;
                Q.push(T);
            }
            if (index < data.length() - 1) {
                val = read_node(data, index, is_null);
                if (!is_null) {
                    T = new TreeNode(val);
                    parent->right = T;
                    Q.push(T);
                }
            }
        }
    }
    return root;
}

int read_node(string data, int& index, bool& is_null)
{
    is_null = false;
    int val = 0;
    bool is_minus = false;
    while (data[index] != ',') {
        if (data[index] == 'n') {
            is_null = true;
            index += 5;
            return 0;
        } else if (data[index] == '-') {
            is_minus = true;
        } else {
            val = val * 10 + data[index] - '0';
        }
        index++;
    }
    index++;
    if (is_minus) {
        val = -val;
    }
    return val;
}

int main()
{
    TreeNode T(10), t1(2), t2(-3), t3(4), t4(5);
    T.left = &t1;
    T.right = &t2;
    t2.left = &t3;
    t2.right = &t4;
    cout << serialize(&T) << endl;
    string str = serialize(&T);
    TreeNode* root = deserialize(str);
    cout << root->val << " " << root->left->val << " " << root->right->val << endl;
    cout << serialize(root) << endl;
    return 0;
}

/**
 * 32ms解法
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        visitSer(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss;
        iss.str(data);
        return visitDes(iss);
    }
    
private:
    void visitSer(TreeNode* node, ostringstream& oss) {
        if(node == NULL) {
            oss << " " << "N";
            return;            
        }
        oss << " " << node->val;
        visitSer(node->left, oss);
        visitSer(node->right, oss);
    }
    TreeNode* visitDes(istringstream& iss) {
        string val;
        iss >> val;
        if(val == "N")
            return NULL;
        TreeNode* res = new TreeNode(stoi(val));
        res->left = visitDes(iss);
        res->right = visitDes(iss);
        return res;
    }
};


