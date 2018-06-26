/**
 * 282. Expression Add Operators
 *
 * Given a string that contains only digits 0-9 and a target value, return all 
 * possibilities to add binary operators (not unary) +, -, or * between the 
 * digits so they evaluate to the target value.
 *
 * Example 1:
 *     Input: num = "123", target = 6
 *     Output: ["1+2+3", "1*2*3"] 
 * 
 * Example 2:
 *     Input: num = "232", target = 8
 *     Output: ["2*3+2", "2+3*2"]
 *     
 * Example 3:
 *     Input: num = "105", target = 5
 *     Output: ["1*0+5","10-5"]
 * 
 * Example 4:
 *     Input: num = "00", target = 0
 *     Output: ["0+0", "0-0", "0*0"]
 * 
 * Example 5:
 *     Input: num = "3456237490", target = 9191
 *     Output: []
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

void dfs(vector<string>& solution, string& num, string res, int index, long long cur_target, int multed, int target);

vector<string> addOperators(string num, int target) 
{
    string res = "";
    vector<string> solution;
    if (num.length() == 0) {
        return solution;
    }
    dfs(solution, num, res, 0, 0, 0, target);
    return solution;
}

void dfs(vector<string>& solution, string& num, string res, int index, long long cur_target, int multed, int target)
{
    if (index >= num.length()) {
        if (cur_target == target) {
            solution.push_back(res);
        }
        return;
    }
    long long cur = 0;
    for (int i = index; i < num.length(); i++) {
        if (index == 0) {
            string temp(num, index, i + 1 - index);
            if (num[index] == '0' && i > index) {
                continue;
            }
            cur = cur * 10 + num[i] - '0';
            cur_target = cur;
            dfs(solution, num, temp, i + 1, cur_target, cur_target, target);
            continue;
        }
        string temp(num, index, i + 1 - index);
        if (temp.front() == '0' && temp.length() > 1) {
            continue;
        }
        cur = cur * 10 + num[i] - '0';
        dfs(solution, num, res + '+' + temp, i + 1, cur_target + cur, cur, target);
        dfs(solution, num, res + '-' + temp, i + 1, cur_target - cur, -cur, target);
        dfs(solution, num, res + '*' + temp, i + 1, cur_target - multed + multed * cur, multed * cur, target);
    }
}

int main()
{
    string num = "00";
    int target = 0;
    vector<string> result = addOperators(num, target);
    for (auto str: result) {
        cout << str << endl;
    }
    return 0;
}

