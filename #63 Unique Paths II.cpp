/**
 * 63. Unique Paths II
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(obstacleGrid, cache, 0, 0, m, n);
    }

    int dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& cache, int i, int j, int m, int n)
    {
        if (obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i + 1 == m && j + 1 == n) {
            return 1;
        }
        if (cache[i][j] != -1) {
            return cache[i][j];
        }
        int paths = 0;
        if (i + 1 < m) {
            paths += dfs(obstacleGrid, cache, i + 1, j, m, n);
        }
        if (j + 1 < n) {
            paths += dfs(obstacleGrid, cache, i, j + 1, m, n);
        }
        cache[i][j] = paths;
        return paths;
    }
};
