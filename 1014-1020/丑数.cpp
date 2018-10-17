/**
 * 丑数
 * https://leetcode.com/problems/ugly-number-ii/
 * 
 * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，
 * 因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) 
    {
        if (n <= 5) {
            return n;
        }
        vector<int> uglys(n, 0);
        uglys[0] = 1;
        int ptr2 = 0, ptr3 = 0, ptr5 = 0;
        for (int i = 1; i < n; i++) {
            int min_val = min(uglys[ptr2] * 2, min(uglys[ptr3] * 3, uglys[ptr5] * 5));
            if (min_val == uglys[ptr2] * 2) {
                ptr2++;
            }
            if (min_val == uglys[ptr3] * 3) {
                ptr3++;
            }
            if (min_val == uglys[ptr5] * 5) {
                ptr5++;
            }
            uglys[i] = min_val;
        }
        return uglys[n - 1];
    }
};
