/**
 * 292. Nim Game
 * https://leetcode.com/problems/nim-game/description/
 *
 * You are playing the following Nim Game with your friend: There is a heap of stones on the table, 
 * each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will 
 * be the winner. You will take the first turn to remove the stones.
 * 
 * Both of you are very clever and have optimal strategies for the game. Write a function to determine 
 * whether you can win the game given the number of stones in the heap.
 *
 * Example:
 *     Input: 4
 *     Output: false 
 *     Explanation: If there are 4 stones in the heap, then you will never win the game;
 *                  No matter 1, 2, or 3 stones you remove, the last stone will always be 
 *                  removed by your friend.
 */

#include <iostream>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
    
    bool search(int n, int turns)
    {
        if (n <= 3) {
            if (turns % 2 == 0) {
                return true;
            } else {
                return false;
            }
        }
        for (int i = 1; i <= 3; i++) {
            if (search(n - i, turns + 1)) {
                return true;
            }
        }
        return false;
    }
};
