/**
 * 数组中出现次数超过一半的数字
 * https://leetcode.com/problems/majority-element/
 *
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> count;
        int n = nums.size();
        for (int num: nums) {
            if (count.find(num) == count.end()) {
                count[num] = 1;
            } else {
                count[num] += 1;
            }
            if (count[num] >= n / 2.0) {
                return num;
            }
        }
        return 0;
    }

    int boyerMoore(vector<int>& nums)
    {
        int cnt = 0;
        int candidate;
        for (int num: nums) {
            if (cnt == 0) {
                candidate = num;
            }
            cnt += (candidate == num) ? 1 : -1;
        }
        return candidate;
    }
};
