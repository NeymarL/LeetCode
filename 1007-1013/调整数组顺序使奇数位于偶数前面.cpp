/**
 * 调整数组顺序使奇数位于偶数前面
 * https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
 * 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) 
    {
        vector<int> tmp(array.size(), 0);
        merge(array, tmp, 0, array.size());
    }

    void merge(vector<int>& array, vector<int>& tmp, int l, int r)
    {
        if (r - l <= 1) {
            return;
        }
        int mid = (l + r) / 2;
        merge(array, tmp, l, mid);
        merge(array, tmp, mid, r);
        int i = l, j = mid, k = l;
        while (i < mid && array[i] % 2 == 1) tmp[k++] = array[i++];
        while (j < r && array[j] % 2 == 1) tmp[k++] = array[j++];
        while (i < mid) tmp[k++] = array[i++];
        while (j < r) tmp[k++] = array[j++];
        for (i = l; i < r; i++) {
            array[i] = tmp[i];
        }
    }
};
