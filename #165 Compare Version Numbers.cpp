/**
 * 165. Compare Version Numbers
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
 * 
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level 
 * revision of the second first-level revision.
 *
 * Example 1:
 *     Input: version1 = "0.1", version2 = "1.1"
 *     Output: -1
 *     
 * Example 2:
 *     Input: version1 = "1.0.1", version2 = "1"
 *     Output: 1
 *     
 * Example 3:
 *     Input: version1 = "7.5.2.4", version2 = "7.5.3"
 *     Output: -1
 */

#include <iostream>
#include <string>

using namespace std;

int compareVersion(string version1, string version2) 
{
    int idx1 = 0, idx2 = 0;
    while (idx1 < version1.length() || idx2 < version2.length()) {
        string num1 = "0", num2 = "0";
        int n1 = 0, n2 = 0;
        while (version1[idx1] != '.' && idx1 < version1.length()) {
            num1 += version1[idx1++];
        }
        while (version2[idx2] != '.' && idx2 < version2.length()) {
            num2 += version2[idx2++];
        }
        n1 = std::stoi(num1);
        n2 = std::stoi(num2);
        if (n1 > n2) {
            return 1;
        } else if (n1 < n2) {
            return -1;
        } else {
            idx1++;
            idx2++;
        }
    }
    return 0;
}

int main()
{
    string v1 = "7.5.2.4", v2 = "7.5.3";
    cout << compareVersion(v1, v2) << endl;
    return 0;
}



