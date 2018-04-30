/**
 * 150. Evaluate Reverse Polish Notation
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * 
 * Note:
 *     Division between two integers should truncate toward zero.
 *     The given RPN expression is always valid. That means the expression would always 
 *     evaluate to a result and there won't be any divide by zero operation.
 *
 * Example1:
 *     Input: ["2", "1", "+", "3", "*"]
 *     Output: 9
 *     Explanation: ((2 + 1) * 3) = 9
 *
 * Example2:
 *     Input: ["4", "13", "5", "/", "+"]
 *     Output: 6
 *     Explanation: (4 + (13 / 5)) = 6
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool is_oprand(string token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        return true;
    }
    else {
        return false;
    }
}

int evalRPN(vector<string>& tokens) 
{
    stack<int> s;
    for (string token : tokens) {
        if (is_oprand(token)) {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            int result = 0;
            switch(token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = (int)(op1 / op2); break;
            }
            s.push(result);
        }
        else {
            s.push(stoi(token));
        }
    }
    return s.top();
}

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens) << endl;
    return 0;
}
