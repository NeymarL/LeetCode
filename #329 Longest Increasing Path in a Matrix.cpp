/**
 * 329. Longest Increasing Path in a Matrix
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or down. 
 * You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is 
 * not allowed).
 *
 * Example 1:
 *     Input: nums = 
 *            [
 *                [9,9,4],
 *                [6,6,8],
 *                [2,1,1]
 *            ] 
 *     Output: 4 
 *     Explanation: The longest increasing path is [1, 2, 6, 9].
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> cache(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int len = dfs(matrix, cache, i, j, n, m);
                ans = max(ans, len);
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int i, int j, int n, int m)
    {
        if (cache[i][j] != 0) {
            return cache[i][j];
        }
        int len = 1, max_len = 1;
        for (auto dir: dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] <= matrix[i][j]) {
                continue;
            }
            int temp = len + dfs(matrix, cache, x, y, n, m);
            max_len = max(max_len, temp);
        }
        cache[i][j] = max_len;
        return max_len;
    }
};

