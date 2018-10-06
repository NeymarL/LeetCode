/**
 * 二维数组中的查找
 * https://leetcode.com/problems/search-a-2d-matrix-ii/
 *
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
 * 判断数组中是否含有该整数。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        vector<int> first_row = matrix[0];
        int lo = 0, hi = first_row.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // cout << "??" << endl;
            if (first_row[mid] == target) {
                return true;
            } else if (first_row[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        while ((lo >= first_row.size() || first_row[lo] > target) && lo >= 0) lo--;
        int i = lo;
        while (i >= 0) {
            lo = 0, hi = matrix.size();
            if (matrix[hi - 1][i] < target) {
                break;
            }
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (mid == hi) {
                    break;
                }
                if (matrix[mid][i] == target) {
                    cout << "mid = " << mid << " i = " << i << endl;
                    return true;
                } else if (matrix[mid][i] < target) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            i--;
        }
        return false;
    }

    bool searchMatrixMiao(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0) {
            return false;
        }
        int n=matrix[0].size();
        int i=0, j=n-1;
        
        while(i<m && j>=0) {
            if(matrix[i][j] == target) {
                return true;
            }
            
            if(matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17, 24},{18,21,23,26, 30}};
    cout << s.searchMatrix(matrix, -10);
    return 0;
}
