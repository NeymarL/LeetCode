/**
 * 871. Minimum Number of Refueling Stops
 * https://leetcode.com/problems/minimum-number-of-refueling-stops/
 *
 * A car travels from a starting position to a destination which is target miles east of the starting position.
 * 
 * Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] 
 * miles east of the starting position, and has station[i][1] liters of gas.
 * 
 * The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  
 * It uses 1 liter of gas per 1 mile that it drives.
 * 
 * When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
 * 
 * What is the least number of refueling stops the car must make in order to reach its destination?  
 * If it cannot reach the destination, return -1.
 * 
 * Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  
 * If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
 *
 * Example:
 *     Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
 *     Output: 2
 * Explanation: We start with 10 liters of fuel. We drive to position 10, expending 10 liters of fuel.  
 *              We refuel from 0 liters to 60 liters of gas. Then, we drive from position 10 to position 60 
 *              (expending 50 liters of fuel), and refuel from 10 liters to 50 liters of gas.  We then drive 
 *              to and reach the target. We made 2 refueling stops along the way, so we return 2.
 */

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct comp
{
    bool operator()(const vector<int> a, const vector<int> b) const
    {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        // dp[i] = refuel i times, the farest distance that we can reach
        vector<int> dp(1, startFuel);
        int i = 0, j = 0;
        priority_queue<vector<int>, vector<vector<int>>, comp> Q;
        while (dp[i] < target) {
            int last = 0, next = dp[i];
            if (i > 0) {
                last = dp[i - 1];
            }
            while (j < stations.size() && stations[j][0] >= last && stations[j][0] <= dp[i]) {
                // cout << "last = " << last << " dp[i] = " << dp[i] << " j = " << j << endl;
                Q.push(stations[j]);
                j++;
            }
            if (!Q.empty()) {
                vector<int> st = Q.top();
                Q.pop();
                next = max(next, dp[i] + st[1]);
            } else {
                return -1;
            }       
            dp.push_back(next);
            i++;
            cout << dp[i] << endl;
        }
        return i;
    }
};
