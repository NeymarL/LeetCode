/**
 * 和为S的两个数字
 * https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
 * 
 * 对应每个测试案例，输出两个数，小的先输出。
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) 
    {
        int min_mul = INT_MAX;
        vector<int> res = {0, 0};
        unordered_set<int> set;
        for (auto num: array) {
            if (set.find(num) != set.end()) {
                if (num * (sum - num) < min_mul) {
                    min_mul = num * (sum - num);
                    if (num < sum - num) {
                        res[0] = num;
                        res[1] = sum - num;
                    } else {
                        res[0] = sum - num;
                        res[1] = num;
                    }
                }
            }
            set.insert(sum - num);
        }
        if (min_mul == INT_MAX) {
            return vector<int>();
        }
        return res;
    }

    vector<int> FindNumbersWithSum2(vector<int> array,int sum) 
    {
        int i = 0, j = array.size() - 1;
        int min_mul = INT_MAX;
        while (i < j && array[i] + array[j] != sum) {
            if (array[i] + array[j] > sum) {
                j--;
            } else {
                i++;
            }
        }
        if (i < array.size() && j >= 0 && array[i] + array[j] == sum) {
            vector<int> res = {array[i], array[j]};
            return res;
        } else {
            return vector<int>();
        }
    }
};
