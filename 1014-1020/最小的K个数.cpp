/**
 * 最小的K个数
 *
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，
 * 则最小的4个数字是1,2,3,4。
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
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        if (k > input.size()) {
            return vector<int>();
        }
        priority_queue<int, vector<int>, comp> pq;
        for (int num: input) {
            pq.push(num);
        }
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = pq.top();
            pq.pop();
        }
        return result;
    }
};
