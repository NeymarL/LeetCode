/**
 * 123. Best Time to Buy and Sell Stock III
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock 
 * before you buy again).
 *
 * Example:
 *     Input: [7, 1, 5, 3, 6, 4]
 *     Output: 7
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices) 
{
    int release1 = 0, release2 = 0, hold1 = INT_MIN, hold2 = INT_MIN;
    if (prices.size() <= 1) {
        return 0;
    }
    // assume we have 0 money at the begining
    for (int price : prices) {
        release2 = max(release2, hold2 + price);    // sell the 2nd stock on this day
        hold2 = max(hold2, release1 - price);       // buy the 2nd stock on this day
        release1 = max(release1, hold1 + price);    // sell the 1st stock on this day
        hold1 = max(hold1, -price);                 // buy the 2nd stock on this day
    }
    return release2;
}


int main()
{
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    cout << maxProfit(prices) << endl;
    return 0;
}
