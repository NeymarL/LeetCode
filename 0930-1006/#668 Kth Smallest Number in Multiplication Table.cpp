/**
 * 668. Kth Smallest Number in Multiplication Table
 * https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
 *
 * Given the height m and the length n of a m * n Multiplication Table, and a 
 * positive integer k, you need to return the k-th smallest number in this table.
 *
 * Example 1:
 *     
 * Input: m = 3, n = 3, k = 5
 * Output: 
 * Explanation: 
 *     The Multiplication Table:
 *         1   2   3
 *         2   4   6
 *         3   6   9
 *     The 5-th smallest number is 3 (1, 2, 2, 3, 3).
 *
 * Note:
 *     The m and n will be in the range [1, 30000].
 *     The k will be in the range [1, m * n]
 */

#include <iostream>
#include <vector>
#include <math>

using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) 
    {
        int lo = 1, hi = m * n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (!enough(mid, m, n, k)) {
                lo = mid + 1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }

    bool enough(int num, int m, int n, int k)
    {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(num / i, n);
        }
        return cnt >= k;
    }
};
