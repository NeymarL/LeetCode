/**
 * 66. Plus One
 *
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 * The digits are stored such that the most significant digit is at the head of the list.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
    int carry = 1, sum = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
        sum = carry + digits[i];
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        digits[i] = sum;
    }
    if (carry == 1) {
        digits.insert(digits.begin(), carry);
    }
    return digits;
}



int main()
{
    cout << "Input: ";
    std::vector<int> v(9);
    for (int i = 0; i < 9; i++) {
        v[i] = i + 1;
        cout << v[i];
    }
    vector<int> res = plusOne(v);
    cout << endl << "Result: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    cout << endl;
    return 0;
}
