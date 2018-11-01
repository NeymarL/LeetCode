/**
 * 数据流中的中位数
 * https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
 * 使用GetMedian()方法获取当前读取数据的中位数。
 * 
 * Can also use std::multiset, create two pointers always point to the middle element(s)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct comp {
    bool operator() (const int a, const int b) const {
        return a > b;
    }
};

class Solution {
public:
    Solution() 
    {
        count = 0;
    }

    void Insert(int num)
    {
        count++;
        int n = count / 2 + 1;
        if (min_q.size() < n) {
            max_q.push(num);
            num = max_q.top();
            max_q.pop();
            min_q.push(num);
        } else if (num > min_q.top()) {
            max_q.push(min_q.top());
            min_q.pop();
            min_q.push(num);
        } else {
            max_q.push(num);
        }
    }

    double GetMedian()
    { 
        if (count % 2) {
            return min_q.top();
        }
        int tmp = min_q.top();
        min_q.pop();
        double res = (tmp + min_q.top()) / 2.0;
        min_q.push(tmp);
        return res;
    }

private:
    priority_queue<int, vector<int>, comp> min_q;
    priority_queue<int> max_q;
    int count;
};
