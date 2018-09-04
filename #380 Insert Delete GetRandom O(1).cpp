/**
 * 380. Insert Delete GetRandom O(1)
 * https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 *
 * Design a data structure that supports all following operations in average O(1) time.
 *     * insert(val): Inserts an item val to the set if not already present.
 *     * remove(val): Removes an item val from the set if present.
 *     * getRandom: Returns a random element from current set of elements. 
 *                  Each element must have the same probability of being returned.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (indexes.find(val) != indexes.end()) {
            return false;
        }
        indexes[val] = data.size();
        data.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (indexes.find(val) == indexes.end()) {
            return false;
        }
        int last = data.back();
        data.pop_back();
        indexes[last] = indexes[val];
        data[indexes[val]] = last;
        indexes.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
    }

private:
    vector<int> data;
    unordered_map<int, int> indexes;
};

