/**
 * 870. Advantage Shuffle
 * https://leetcode.com/problems/advantage-shuffle/description/
 *
 * Given two arrays A and B of equal size, the advantage of A with respect to B 
 * is the number of indices i for which A[i] > B[i].
 * 
 * Return any permutation of A that maximizes its advantage with respect to B.
 *
 * Example 1:
 *     Input: A = [2,7,11,15], B = [1,10,4,11]
 *     Output: [2,11,7,15]
 *     
 * Example 2:
 *     Input: A = [12,24,8,32], B = [13,25,32,11]
 *     Output: [24,32,8,12]
 *
 * Note:
 *     1. 1 <= A.length = B.length <= 10000
 *     2. 0 <= A[i] <= 10^9
 *     3. 0 <= B[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> remains;
        unordered_map<int, vector<int>> assigned;
        vector<int> sortedA(A), sortedB(B);
        sort(sortedA.begin(), sortedA.end());
        sort(sortedB.begin(), sortedB.end());
        int j = 0;
        for (auto a: sortedA) {
            if (a > sortedB[j]) {
                assigned[sortedB[j++]].push_back(a);
            } else {
                remains.push_back(a);
            }
        }
        // reconstruct
        vector<int> ans(B.size());
        for (int i = 0; i < B.size(); i++) {
            if (assigned[B[i]].size() > 0) {
                ans[i] = assigned[B[i]].back();
                assigned[B[i]].pop_back();
            } else {
                ans[i] = remains.back();
                remains.pop_back();
            }
        }
        return ans;
    }
};
