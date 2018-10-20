/**
 * 和为S的连续正数序列
 * https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) 
    {
        vector<vector<int>> res;
        if (sum < 3) {
            return res;
        }
        int i = round(sqrt(sum));
        while (i * i + i < sum * 2) {
            i++;
        }
        while (i > 1) {
            if (i % 2 == 0) {
                double tmp = sum / (i * 1.0);
                if (tmp - (int)tmp == 0.5) {
                    vector<int> ans;
                    int j = tmp - i / 2 + 1;
                    int cnt = 0;
                    while (cnt < i) {
                        ans.push_back(j++);
                        cnt++;
                    }
                    res.push_back(ans);
                }
            } else {
                if (sum % i == 0) {
                    int tmp = sum / i;
                    vector<int> ans;
                    for (int j = tmp - i / 2; j <= tmp + i / 2; j++) {
                        ans.push_back(j);
                    }
                    res.push_back(ans);
                }
            }
            i--;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> res = sol.FindContinuousSequence(15);
    for (auto vec: res) {
        for (auto num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
