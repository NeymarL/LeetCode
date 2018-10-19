/**
 * 平衡二叉树
 * https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 */

#include <iostream>
#include <unordered_map>

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
    bool IsBalanced_Solution(TreeNode* pRoot) 
    {
        if (!pRoot) {
            return true;
        }
        int l = TreeDepth(pRoot->left);
        int r = TreeDepth(pRoot->right);
        if (abs(l -r) <= 1) {
            return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
        } else {
            return false;
        }
    }

    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL) {
            return 0;
        }
        if (depth.find(pRoot) != depth.end()) {
            return depth[pRoot];
        }
        int h1 = 0, h2 = 0;
        h1 = TreeDepth(pRoot->left) + 1;
        h2 = TreeDepth(pRoot->right) + 1;
        depth[pRoot] = max(h1, h2);
        return depth[pRoot];
    }

private:
    unordered_map<TreeNode*, int> depth;
};

