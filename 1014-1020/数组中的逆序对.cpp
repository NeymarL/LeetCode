/**
 * 数组中的逆序对
 * https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
 * 即输出P%1000000007
 * 
 * 输入：1,2,3,4,5,6,7,0
 * 输出：7
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) 
    {
        int pairs = 0;
        vector<int> tmp(data.size(), 0);
        solution(data, tmp, 0, data.size(), pairs);
        return pairs % 1000000007;
    }

    void solution(vector<int>& data, vector<int>& tmp, int start, int end, int& pairs)
    {
        if (start >= end - 1) {
            return;
        }
        int mid = (start + end) / 2;
        solution(data, tmp, start, mid, pairs);
        solution(data, tmp, mid, end, pairs);
        int p = mid - 1, q = end - 1, i = end - 1;
        while (p >= start && q >= mid) {
            if (data[q] < data[p]) {
                tmp[i--] = data[p--];
                pairs += q + 1 - mid;
                pairs %= 1000000007;
            } else {
                tmp[i--] = data[q--];
            }
        }
        while (p >= start) {
            tmp[i--] = data[p--];
        }
        while (q >= mid) {
            tmp[i--] = data[q--];
        }
        for (int i = start; i < end; i++) {
            data[i] = tmp[i];
        }
        pairs %= 1000000007;
    }
};