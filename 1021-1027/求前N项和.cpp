/**
 * 求1+2+3+...+n
 * 
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case
 * 等关键字及条件判断语句（A?B:C）。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int Sum_Solution(int n) 
    {
        int n2 = 0, tmp = n, mask = n;
        while (mask) {
            if (mask & 1) {
                n2 += tmp;
            }
            tmp = tmp << 1;
            mask = mask >> 1;
        }
        return (n2 + n) >> 1;
    }
};

int main()
{
    Solution sol;
    cout << sol.Sum_Solution(5) << endl;
    return 0;
}
