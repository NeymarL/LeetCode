/**
 * 把字符串转换成整数
 * https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * 
 * 将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
 * 要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int StrToInt(string str) 
    {
        int res = 0;
        bool no_num = true;
        bool negative = false;
        for (char c: str) {
            if (c == ' ') {
                continue;
            }
            if (c == '+' || c == '-') {
                if (no_num) {
                    if (c == '-') {
                        negative = true;
                    }
                    no_num = false;
                } else {
                    return 0;
                }
            } else if (c >= '0' && c <= '9') {
                no_num = false;
                res = res * 10 + c - '0';
            } else {
                return 0;
            }
        }
        if (negative) {
            res = -res;
        }
        return res;
    }
};
