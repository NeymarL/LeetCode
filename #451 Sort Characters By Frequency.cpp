/**
 * 451. Sort Characters By Frequency
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * Given a string, sort it in decreasing order based on the frequency of characters.
 *
 * Example 1:
 *     Input: "tree"
 *     Output: "eert"
 *     Explanation: 'e' appears twice while 'r' and 't' both appear once. So 'e' must 
 *     appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<char, int> m;

string frequencySort(string s) 
{
    vector<char> keys;
    for (char c: s) {
        if (m.find(c) != m.end()) {
            m[c] += 1;
        } else {
            m[c] = 1;
            keys.push_back(c);
        }
    }
    sort(keys.begin(), keys.end(), [](const char& a, const char& b) { return m[a] > m[b]; });
    string result;
    for (char c: keys) {
        for (int i = 0; i < m[c]; ++i) {
            result += c;
        }
    }
    return result;
}

int main()
{
    string s = "Aabb";
    cout << frequencySort(s) << endl;
    return 0;
}
