/**
 * 84. Largest Rectangle in Histogram
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 *
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 *
 * For example,
 *     Given heights = [2,1,5,6,2,3],
 *     return 10.
 */

#include <iostream>
#include <vector>

using namespace std;

int largestRectangleArea_naive(vector<int>& heights) 
{
    int max_area = 0;
    int width = 1;
    int previous = 0;
    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] == previous) {
            continue;
        }
        previous = heights[i];
        width = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (heights[j] < heights[i]) {
                break;
            }
            width++;
        }
        for (int j = i + 1; j < heights.size(); j++) {
            if (heights[j] < heights[i]) {
                break;
            }
            width++;
        }
        if (width * heights[i] > max_area) {
            max_area = width * heights[i];
        }
    }
    return max_area;
}

int largestRectangleArea(vector<int>& heights) 
{
    heights.push_back(0); 
    int len = heights.size(), res = 0, cur=1;
    int s[len + 1]= {0};
    s[0] = -1;
    for (int i = 1; i < len; i++) {
        while (cur && heights[i] < heights[s[cur]])
            res = max(res, heights[s[cur]] * (i - s[--cur] - 1));
        s[++cur] = i;
    }
    return res;
}

