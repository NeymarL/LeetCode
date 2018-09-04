/**
 * 85. Maximal Rectangle
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest 
 * rectangle containing only 1's and return its area.
 *
 * Example:
 *     Input:
 *     [
 *         ["1","0","1","0","0"],
 *         ["1","0","1","1","1"],
 *         ["1","1","1","1","1"],
 *         ["1","0","0","1","0"]
 *     ]
 *     Output: 6
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.size() == 0) {
            return 0;
        }
        vector<int> heights(matrix[0].size(), 0);
        int max_area = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            max_area = max(max_area, largestRectangleArea(heights));
        }
        return max_area;
    }

    int largestRectangleArea(vector<int> &height) {
        int ret = 0;
        height.push_back(0);
        vector<int> index;
        for(int i = 0; i < height.size(); i++)
        {
            while(index.size() > 0 && height[index.back()] >= height[i])
            {
                int h = height[index.back()];
                index.pop_back();
                
                int sidx = index.size() > 0 ? index.back() : -1;
                if (h * (i-sidx-1) > ret)
                    ret = h * (i-sidx-1);
            }
            index.push_back(i);
        }
        return ret;
    }
};
