/**
 * 650. 2 Keys Keyboard
 * https://leetcode.com/problems/2-keys-keyboard/description/
 *
 * Initially on a notepad only one character 'A' is present. 
 * You can perform two operations on this notepad for each step:
 *     1. Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
 *     2. Paste: You can paste the characters which are copied last time.
 * Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of 
 * steps permitted. Output the minimum number of steps to get n 'A'.
 *
 * Example 1:
 *     Input: 3
 *     Output: 3
 *     Explanation:
 *         Intitally, we have one character 'A'.
 *         In step 1, we use Copy All operation.
 *         In step 2, we use Paste operation to get 'AA'.
 *         In step 3, we use Paste operation to get 'AAA'.
 *
 * Note: The n will be in the range [1, 1000].
 * 1 - 0, 2 - 2, 3 - 3, 4 - 4, 5 - 5, 6 - 5, 7 - 7, 8 - 6
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minSteps(int n) 
{
    if (n == 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return minSteps(i) + minSteps(n / i);
        }
    }
    return n;
}

int main()
{
    cout << minSteps(6) << endl;
    return 0;
}