/**
 * 173. Binary Search Tree Iterator
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will 
 * be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
 * where h is the height of the tree.
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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        T = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (T == NULL && S.empty()) {
            return false;
        } else {
            return true;
        }
    }

    /** @return the next smallest number */
    int next() {
        while (T) {
            S.push(T);
            T = T->left;
        }
        T = S.top();
        S.pop();
        TreeNode* tmp = T;
        T = T->right;
        return tmp->val;
    }

private:
    TreeNode* T;
    stack<TreeNode*> S;
};

int main()
{
    TreeNode root(3);
    TreeNode t1(1), t2(4), t3(0), t4(5);
    root.left = &t1;
    root.right = &t2;
    t1.left = &t3;
    t2.right = &t4;
    BSTIterator i = BSTIterator(&root);
    while (i.hasNext()) {
        cout << i.next() << " ";
    }
    cout << endl;
    return 0;
}