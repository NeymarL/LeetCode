/**
 * 圆圈中最后剩下的数
 * 
 * 首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
 * 每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
 * 从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
 * 可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,
 * 哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<int> ring(n);
        for (int i = 0; i < n; i++) {
            ring[i] = i;
        }
        int cnt = n;
        int start = 0;
        while (cnt > 1) {
            int target = (start + m - 1) % ring.size();
            ring.erase(ring.begin() + target, ring.begin() + target + 1);
            start = target % ring.size();
            cnt--;
        }
        return ring[0];
    }

    /**
     * F[n] = 第 N - n 轮的淘汰者所在的位置，总共有 N 个小朋友
     * 由定义可知：F[1] = 0 （最后一轮只剩一个人，他的位置只能是0）
     * 由于每轮迭代，相当于把所有人的下标减了 m，所以根据下轮的位置可以还原出上轮的位置：
     *      F[n] = (F[n - 1] + m) % n
     */
    int LastRemaining_Solution2(int n, int m)
    {
        int f = 0;
        for (int i = 2; i <= n; i++) {
            f = (f + m) % i;
        }
        return f;
    }
};

int main()
{
    Solution sol;
    cout << sol.LastRemaining_Solution(5, 3) << endl;
    return 0;
}
