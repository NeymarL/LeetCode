/**
 * 42. Trapping Rain Water
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * Given n non-negative integers representing an elevation map where 
 * the width of each bar is 1, compute how much water it is able to 
 * trap after raining.
 *
 * Example:
 *     Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 *     Output: 6
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int>& height) 
{
    int trapped = 0;
    stack<int> s;
    if (height.size() <= 2) {
        return 0;
    }
    for (int i = 0; i < height.size(); i++) {
        if (height[i] < height[s.top()]) {
            s.push(i);
        }
        else {
            while (!s.empty() && height[i] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty()) {
                    break;
                }
                int distance = i - s.top() - 1;
                int bounded_height = min(height[i], height[s.top()]) - height[top];
                trapped += bounded_height * distance;
            }
        }
        s.push(i);
    }
    return trapped;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    return 0;
}
