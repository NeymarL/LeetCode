/**
 * 顺时针打印矩阵
 * https://leetcode.com/problems/spiral-matrix/
 *
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        if (m == 0) {
            return vector<int>();
        }
        int n = matrix[0].size();
        if (n == 0) {
            return vector<int>();
        }
        int count = m * n, i = 0, j = 0, k = 0;
        int l = 0, r = n, u = 1, d = m;
        bool go_right = true, go_down = false, go_left = false, go_up = false;
        vector<int> res(count, 0);
        while (k < count) {
            if (go_right) {
                if (j < r)
                    res[k] = matrix[i][j++];
                if (j == r) {
                    j = r - 1;
                    i++;
                    r--;        // right edge move inner
                    go_right = false;
                    go_down = true;
                }
            }
            else if (go_down) {
                if (i < d)
                    res[k] = matrix[i++][j];
                if (i == d) {
                    i = d - 1;
                    j--;
                    d--;
                    go_down = false;
                    go_left = true;
                }
            }
            else if (go_left) {
                if (j >= l)
                    res[k] = matrix[i][j--];
                if (j < l) {
                    j = l;
                    i--;
                    l++;
                    go_left = false;
                    go_up = true;
                }
            }
            else if (go_up) {
                if (i >= u)
                    res[k] = matrix[i--][j];
                if (i < u) {
                    i = u;
                    j++;
                    u++;
                    go_up = false;
                    go_right = true;
                }
            }
            k++;
        }
        return res;
    }
};
