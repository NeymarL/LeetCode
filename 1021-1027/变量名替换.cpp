#include <iostream>
#include <string>
#include <vector>

using namespace std;

string lower(string s) 
{
    for (auto& c: s) {
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
    }
    return s;
}

bool is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

string transform(string& s)
{
    vector<string> words;
    int last = 0;
    bool has_lower = false;
    for (int i = 1; i < s.length(); i++) {
        if (is_upper(s[i])) {
            if (i == last) {
                continue;
            }
            // oneVariable, OneHTTPRequest
            if ((i < s.length() - 1 && !is_upper(s[i + 1])) || i == s.length() - 1) {
                if (i == s.length() - 1) {
                    words.push_back(lower(s.substr(last, i - last + 1)));
                } else {
                    words.push_back(lower(s.substr(last, i - last)));
                }
                last = i;
                has_lower = false;
            }
            else if (has_lower) {
                words.push_back(lower(s.substr(last, i - last)));
                last = i;
                has_lower = false;
            }
        }
        else if (i == s.length() - 1) {
            words.push_back(lower(s.substr(last, i - last + 1)));
        } 
        else {
            has_lower = true;
        }
    }
    if (words.size() == 0) {
        return lower(s);
    }
    string res = "";
    for (int i = 0; i < words.size(); i++) {
        res += words[i];
        if (i != words.size() - 1) {
            res += '_';
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strs(n, "");
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    vector<string> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = transform(strs[i]);
        cout << result[i] << endl;
    }
    return 0;
}
