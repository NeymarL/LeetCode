/**
 * 120. Triangle
 * https://leetcode.com/problems/triangle/description/
 *
 * Given a triangle, find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * [
 *     [2],
 *    [3,4],
 *   [6,5,7],
 *  [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note: Bonus point if you are able to do this using only O(n) extra space, 
 * where n is the total number of rows in the triangle.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        if (n == 0) {
            return 0;
        }
        vector<int> cache(n, INT_MAX);
        vector<int> temp(n, INT_MAX);
        for (int i = 0; i < n - 1; i++) {
            temp[0] = cache[0];
            temp[1] = cache[1];
            if (cache[0] == INT_MAX)
                cache[0] = triangle[i][0];
            else
                cache[0] += triangle[i][0];
            if (cache[1] == INT_MAX)
                cache[1] = triangle[i][1];
            else
                cache[1] += triangle[i][1];
            for (int j = 1; j <= i; j++) {
                if (j != 1)
                    temp[j] = cache[j];
                if (cache[j] > temp[j] + triangle[i + 1][j]) {
                    cache[j] > temp[j] + triangle[i + 1][j];
                }
                if (cache[j + 1] > temp[j] + triangle[i + 1][j + 1]) {
                    cache[j + 1] > temp[j] + triangle[i + 1][j + 1];
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (cache[i] < ans) {
                ans = cache[i];
            }
        }
        return ans;
    }

    int minimumTotal_ON2_space(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> cache(n);
        for (int i = 0; i < n; i++) {
            cache.push_back(vector<int>(i + 1, INT_MAX));
        }
        cache[0][0] = triangle[0][0];
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j <= i; j++) {
                if (cache[i + 1][j] > cache[i][j] + triangle[i + 1][j]) {
                    cache[i + 1][j] = cache[i][j] + triangle[i + 1][j];
                }
                if (cache[i + 1][j + 1] > cache[i][j] + triangle[i + 1][j + 1]) {
                    cache[i + 1][j + 1] = cache[i][j] + triangle[i + 1][j + 1];
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (cache[n - 1][i] < ans) {
                ans = cache[n - 1][i];
            }
        }
        return ans;
    }
};

