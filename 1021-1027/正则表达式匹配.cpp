/**
 * 正则表达式匹配
 * https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * 
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
 * 而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        char *s = str, *p = pattern;
        char tmp;
        while (*s != '\0' && *p != '\0') {
            if (*(p + 1) == '*') {
                if (*p != *s && *p != '.') {
                    // match zero time
                    p += 2;
                } else {
                    // match one or more times
                    if (*p == '.') {
                        while (*s != '\0') {
                            tmp = *s;
                            s++;
                        }
                        break;
                    } else {
                        tmp = *p;
                    }
                    while (*s != '\0' && tmp == *s) {
                        s++;
                    }
                    p = p + 2;
                    while (*p != '\0' && tmp == *p) {
                        p++;
                    }
                }
            } else if (*p == '.') {
                s++;
                p++;
            } else {
                if (*s != *p) {
                    return false;
                }
                s++;
                p++;
            }
        }
        if (*p == '\0' && *s != '\0') {
            return false;
        }
        while (*p != '\0') {
            if (*(p + 1) == '*') {
                p += 2;
            } else if (*p == tmp) {
                p++;
            } else {
                return false;
            }
        }
        return true;
    }
};
