/**
 * 503. Next Greater Element II
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * Given a circular array (the next element of the last element is the first element 
 * of the array), print the Next Greater Number for every element. The Next Greater 
 * Number of a number x is the first greater number to its traversing-order next in 
 * the array, which means you could search circularly to find its next greater number. 
 * If it doesn't exist, output -1 for this number.
 *
 * Example:
 *     Input: [1,2,1]
 *     Output: [2,-1,2]
 *     Explanation: The first 1's next greater number is 2; 
 *     The number 2 can't find next greater number;
 *     The second 1's next greater number needs to search circularly, which is also 2.
 *
 * Note: The length of given array won't exceed 10000.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) 
{
    int n = nums.size();
    std::vector<int> result(n, -1);
    stack<int> indexes;
    for (int i = 0; i < 2 * n; i++) {
        int num = nums[i % n];
        while (!indexes.empty() && nums[indexes.top()] < num) {
            result[indexes.top()] = num;
            // cout << "pop " << indexes.top() << endl;
            indexes.pop();
        }
        if (i < n) {
            indexes.push(i);
            // cout << "push " << i << endl;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 1};
    vector<int> res = nextGreaterElements(nums);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
