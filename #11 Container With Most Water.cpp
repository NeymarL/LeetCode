/**
 * 11. Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two 
 * lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Example:
 *     Input: [1,8,6,2,5,4,8,3,7]
 *     Output: 49
 */

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) 
{
    int maxarea = 0;
    int n = height.size();
    int i = 0, j = n - 1;
    while (j - i >= 1) {
        int area = min(height[i], height[j]) * (j - i);
        if (area > maxarea) {
            maxarea = area;
        }
        if (height[i] > height[j]) {
            j--;
        } else {
            i++;
        }
    }
    return maxarea;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 0;
}
