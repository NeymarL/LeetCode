/**
 * 363. Max Sum of Rectangle No Larger Than K
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle 
 * in the matrix such that its sum is no larger than k.
 *
 * Example:
 *     Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 *     Output: 2 
 *     Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
 *                  and 2 is the max number no larger than k (k = 2).
 * Note:
 *     The rectangle inside the matrix must have an area > 0.
 *     What if the number of rows is much larger than the number of columns?
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
{
    if (matrix.size() == 0) {
        return 0;
    }
    int n = matrix[0].size();
    vector temp(n, 0);
    int current_sum = max_sum = 0;
    for (int l = 0; l < matrix.size(); l++) {
        fill(temp.begin(), temp.end(), 0);
        for (int r = l; r < matrix.size(); r++) {
            current_sum = 0;
            set<int> cumset;
            cumset.insert(0);
            for (int i = 0; i < n; i++) {
                temp[i] += matrix[r][i];
                current_sum += temp[i];
                set<int>::iterator sit = cumset.lower_bound(current_sum - k);
                if (sit != cumset.end()) {
                    max_sum = max(max_sum, current_sum - *sit);
                }
                cumset.insert(current_sum);
            }
        }
    }
    return max_sum;
}
