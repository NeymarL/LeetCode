/**
 * 172. Factorial Trailing Zeroes
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 *     Input: 3
 *     Output: 0
 *     Explanation: 3! = 6, no trailing zero.
 *
 * Example 2:
 *     Input: 5
 *     Output: 1
 *     Explanation: 5! = 120, one trailing zero.
 *
 * Note: Your solution should be in logarithmic time complexity.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int trailingZeroes(int n) 
{
    int rc = 0;
    while (n = n / 5) rc += n; 
    return rc;
    // return n / 5 + n / 25 + n / 200 + n / 250 + n / 375;
}
