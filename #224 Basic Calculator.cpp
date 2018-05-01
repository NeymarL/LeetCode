/**
 * 224. Basic Calculator
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string may contain open ( and closing parentheses ), 
 * the plus + or minus sign -, non-negative integers and empty spaces .
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 *     "1 + 1" = 2
 *     " 2-1 + 2 " = 3
 *     "(1+(4+5+2)-3)+(6+8)" = 23
 *
 * Note: Do not use the eval built-in library function.
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int evalRPN(vector<string>& tokens);

int calculate(string s) 
{
    stack<char> op_stack;
    vector<string> rpn_tokens;
    string number = "";
    for (char c : s) {
        if (c == ' ') {
            if (number != "") {
                rpn_tokens.push_back(number);
                number = "";
            }
            continue;
        }
        else if (c == '(') {
            if (number != "") {
                rpn_tokens.push_back(number);
                number = "";
            }
            // 左括号压栈
            op_stack.push(c);
        }
        else if (c == ')') {
            if (number != "") {
                rpn_tokens.push_back(number);
                number = "";
            }
            // 将栈顶运算符弹出并输出，直到遇到左括号
            char tmp = op_stack.top();
            op_stack.pop();
            while (tmp != '(') {
                rpn_tokens.push_back(string(1, tmp));
                tmp = op_stack.top();
                op_stack.pop();
            }
        }
        else if (c == '+' || c == '-') {
            if (number != "") {
                rpn_tokens.push_back(number);
                number = "";
            }
            if (!op_stack.empty()) {
                char tmp = op_stack.top();
                // 若优先级小于等于栈顶运算符，则弹出并输出，直到优先级大于栈顶运算符
                while (tmp == '+' || tmp == '-') {
                    op_stack.pop();
                    rpn_tokens.push_back(string(1, tmp));
                    if (!op_stack.empty()) {
                        tmp = op_stack.top();
                    }
                    else {
                        break;
                    }
                }
                // 若优先级大于栈顶运算符，则把它压栈
                op_stack.push(c);
            }
            else {
                // 若优先级大于栈顶运算符，则把它压栈
                op_stack.push(c);
            }
        }
        else {
            number += c;
        }
    }
    if (number != "") {
        rpn_tokens.push_back(number);
        number = "";
    }
    while (!op_stack.empty()) {
        char tmp = op_stack.top();
        op_stack.pop();
        rpn_tokens.push_back(string(1, tmp));
    }
    // for (auto token: rpn_tokens) {
    //     cout << token << " ";
    // }
    // cout << endl;
    return evalRPN(rpn_tokens);
}

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
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << calculate(s) << endl;
    return 0;
}
