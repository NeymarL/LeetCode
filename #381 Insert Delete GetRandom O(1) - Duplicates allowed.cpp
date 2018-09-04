/**
 * 381. Insert Delete GetRandom O(1) - Duplicates allowed
 * https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
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

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool not_has = true;
        if (indexes.find(val) != indexes.end()) {
            not_has = false;
        }
        if (not_has) {
            indexes[val] = vector<int>(1, data.size());
        } else {
            indexes[val].push_back(data.size());
        }
        data.push_back(val);
        return not_has;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (indexes.find(val) == indexes.end()) {
            return false;
        } 
        int last = data.back();
        for (int i = 0; i < indexes[last].size(); i++) {
            if (indexes[last][i] == data.size() - 1) {
                indexes[last][i] = indexes[val].back();
            }
        }
        data[indexes[val].back()] = last;
        indexes[val].pop_back();
        if (indexes[val].empty()) {
            indexes.erase(val);
        }
        data.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
    }

private:
    vector<int> data;
    unordered_map<int, vector<int>> indexes;
};

