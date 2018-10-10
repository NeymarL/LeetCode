/**
 * 二叉搜索树的后序遍历序列
 * https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 *
 * Simple Solution
 * 判断是否是二叉排序树的方法：首先，找到第一个大于根结点的结点位置，将数组分为两部分，判断右子树中的全部结点是否均大于根结点的值
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) 
    {
        if (sequence.size() == 0) {
            return false;
        }
        vector<int> midOrder(sequence);
        sort(midOrder.begin(), midOrder.end());
        int n = sequence.size();
        return check(midOrder, sequence, 0, n, 0, n);
    }

    bool check(vector<int>& midOrder, vector<int>& postOrder, int mstart, int mend, int pstart, int pend)
    {
        cout << mstart << " " << mend << " " << pstart << " " << pend << endl << endl;
        if (mend - mstart == 1) {
            return midOrder[mstart] == postOrder[pstart];
        }
        if (mstart >= mend && pstart >= pend) {
            return true;
        }
        int root = postOrder[pend - 1];
        for (int i = mstart; i < mend; i++) {
            if (midOrder[i] == root) {
                return check(midOrder, postOrder, mstart, i, pstart, pstart + i - mstart) &&
                       check(midOrder, postOrder, i + 1, mend, pstart + i - mstart, pend - 1);
            }
        }
        return false;
    }
};

int main()
{
    vector<int> s = {4, 6, 7, 5};
    Solution sol;
    cout << sol.VerifySquenceOfBST(s) << endl;
    return 0;
}
