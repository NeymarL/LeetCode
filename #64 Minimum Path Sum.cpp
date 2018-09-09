/**
 * 64. Minimum Path Sum
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top 
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(grid, cache, 0, 0, m, n);
    }

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& cache, int i, int j, int m, int n)
    {
        if (i + 1 == m && j + 1 == n) {
            return grid[i][j];
        }
        if (cache[i][j] != -1) {
            return cache[i][j];
        }
        int sum = INT_MAX;
        if (i + 1 < m) {
            sum = min(sum, grid[i][j] + dfs(grid, cache, i + 1, j, m, n));
        }
        if (j + 1 < n) {
            sum = min(sum, grid[i][j] + dfs(grid, cache, i, j + 1, m, n));
        }
        cache[i][j] = sum;
        return sum;
    }
};
