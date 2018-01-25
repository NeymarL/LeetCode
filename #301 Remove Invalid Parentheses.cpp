/* 
301. Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
    "()())()" -> ["()()()", "(())()"]
    "(a)())()" -> ["(a)()()", "(a())()"]
    ")(" -> [""]
    "()(((()"
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(int pair, int index, int remove_left, int remove_right, string solution, const string& s, unordered_set<string>& result);

vector<string> removeInvalidParentheses(string s) 
{
    std::unordered_set<string> res_set; // 用于处理重复字符串
    int remove_left = 0, remove_right = 0;

    // 计算出需要删除多少个左括号和右括号
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            remove_left++;
        } else if (s[i] == ')') {
            if (remove_left > 0) {
                remove_left--;
            } else {
                remove_right++;
            }
        }
    }
    dfs(0, 0, remove_left, remove_right, "", s, res_set);
    return vector<string>(res_set.begin(), res_set.end());
}

/**
 * 深度优先搜索
 * @param pair         未匹配的左括号数
 * @param index        当前遍历的节点（下标）
 * @param remove_left  需要移除的左括号数
 * @param remove_right 需要移除的右括号数
 * @param solution     某个解决方案
 * @param s            输入字符串
 * @param result       结果数组
 */
void dfs(int pair, int index, int remove_left, int remove_right, string solution, const string& s, unordered_set<string>& result)
{
    // 递归到最后，检查solution是否合法
    if (index == s.size()) {
        if (pair == 0 && remove_right == 0 && remove_left == 0) {
            result.insert(solution);
        }
        return;
    }

    if (s[index] == '(') {
        if (remove_left > 0) {
            // 删除这个左括号
            dfs(pair, index + 1, remove_left - 1, remove_right, solution, s, result);
        }
        // 保留它
        dfs(pair + 1, index + 1, remove_left, remove_right, solution + s[index], s, result);
    }
    else if (s[index] == ')') {
        if (remove_right > 0) {
            // 删除这个右括号
            dfs(pair, index + 1, remove_left, remove_right - 1, solution, s, result);
        }
        if (pair > 0) {
            // 保留它
            dfs(pair - 1, index + 1, remove_left, remove_right, solution + s[index], s, result);
        }
    }
    else {
        // 其他字符
        dfs(pair, index + 1, remove_left, remove_right, solution + s[index], s, result);
    }
}


int main()
{
    string s = "()())()";
    std::vector<string> result = removeInvalidParentheses(s);
    cout << "Input: " << s << endl;
    cout << "Result: " << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"";
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
