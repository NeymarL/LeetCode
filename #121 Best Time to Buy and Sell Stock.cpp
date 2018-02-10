/**
 * 121. Best Time to Buy and Sell Stock
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one 
 * share of the stock), design an algorithm to find the maximum profit.
 *
 * Example 1:
 *     Input: [7, 1, 5, 3, 6, 4]
 *     Output: 5
 *     max difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 *
 * Example 2:
 *     Input: [7, 6, 4, 3, 1]
 *     Output: 0
 *     In this case, no transaction is done, i.e. max profit = 0.
 */

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{   
    int minPrice, maxPro = 0;
    if (prices.size() <= 1) {
        return 0;
    }
    minPrice = prices[0];
    for (int price : prices) {
        if (price > minPrice) {
            if (price - minPrice > maxPro) {
                maxPro = price - minPrice;
            }
        } else {
            minPrice = price;
        }
    }
    return maxPro;
}

int main()
{
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
    return 0;
}
