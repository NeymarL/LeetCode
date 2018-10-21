#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string res = "";
    int last_op = 0;  // 1: insert, 2: delete
    char del = '\0';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'i') {
            if (res.length() != 0) {
                del = res[res.length() - 1];
                res.erase(res.length() - 1, 1);
                last_op = 2;
            }
        }
        else if (s[i] == 'o') {
            if (last_op == 1) {
                res.erase(res.length() - 1, 1);
            }
            if (last_op == 2) {
                res += del;
            }
        }
        else {
            res += s[i];
            last_op = 1;
            del = '\0';
        }
    }
    cout << res << endl;
    return 0;
}
