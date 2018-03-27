/**
 * 188. Best Time to Buy and Sell Stock IV
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock 
 * before you buy again).
 *
 * Target: DP
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(int K, vector<int>& prices) 
{
    // f[k][i] represent max profit until day i using at most k transactions
    // f[k][i] = max(f[k][i-1], f[k-1][j] + prices[i] - prices[j])  {j in range [0, i]}
    //         = max(f[k][i-1], prices[i] + max(f[k-1][j] - prices[j]))
    // f[k][0] = 0, f[0][i] = 0
    if (prices.size() <= 1) {
        return 0;
    }
    if (K > prices.size() / 2){ // simple case
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i){
            ans += max(prices[i] - prices[i-1], 0);
        }
        return ans;
    }
    vector<vector<int>> f(2, vector<int>(prices.size(), 0));
    for (int k = 1; k <= K; k++) {
        int maxJ = f[(k - 1) % 2][0] - prices[0];
        for (int i = 1; i < prices.size(); i++) {
            f[k % 2][i] = max(f[k % 2][i-1], prices[i] + maxJ);
            maxJ = max(maxJ, f[(k - 1) % 2][i] - prices[i]);
        }
    }
    return f[K % 2][prices.size() - 1];
}

int main()
{
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    cout << maxProfit(2, prices) << endl;
    return 0;
}
