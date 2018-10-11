/**
 * 二叉搜索树与双向链表
 * https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode *p = root, *pre = NULL, *head = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            if (!s.empty()) {
                p = s.top();
                s.pop();
                TreeNode* tmp = p->right;
                if (pre == NULL) {
                    p->left = NULL;
                    pre = p;
                    head = p;
                } else {
                    pre->right = p;
                    p->left = pre;
                    pre = p;
                }
                p = tmp;
            }
        }
        return head;
    }
};
