/**
 * 49. Group Anagrams
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *     Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 *     Output:
 *     [
 *         ["ate","eat","tea"],
 *         ["nat","tan"],
 *         ["bat"]
 *     ]
 *
 * Note:
 *     All inputs will be in lowercase.
 *     The order of your output does not matter.
 *
 * hash key: #1#2#3#0#0#0...#0, value: abbccc
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string get_hash_key(string& src);

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    unordered_map<string, vector<string>> result;
    for (string str: strs) {
        string key = get_hash_key(str);
        if (result.find(key) != result.end()) {
            result[key].push_back(str);
        }
        else {
            result[key] = vector<string>(1, str);
        }
    }
    vector<vector<string>> res;
    for (auto ite: result) {
        res.push_back(ite.second);
    }
    return res;
}

string get_hash_key(string& src)
{
    int count[26] = {0};
    for (int i = 0; i < src.length(); i++) {
        count[src[i] - 'a']++;
    }
    string key = "";
    for (int i = 0; i < 26; i++) {
        key += '#';
        key += (char)(count[i] + '0');
    }
    return key;
}

int main()
{
    string str = "abbccc";
    cout << get_hash_key(str) << endl;
    return 0;
}
