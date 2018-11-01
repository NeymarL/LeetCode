/**
 * 二叉搜索树的第k个结点
 * https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * 
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。例如,（5，3，7，2，4，6，8）中，
 * 按结点数值大小顺序第三小结点的值为4。
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        stack<TreeNode*> st;
        TreeNode* p = pRoot;
        int i = 0;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            if (!st.empty()) {
                p = st.top();
                st.pop();
                if (++i == k) {
                    return p;
                }
                p = p->right;
            }
        }
        return NULL;
    }
};