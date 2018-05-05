/**
 * 332. Reconstruct Itinerary
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
 * reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, 
 * the itinerary must begin with JFK.
 *
 * Note:
 *     1. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical 
 *     order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order 
 *     than ["JFK", "LGB"].
 *     2. All airports are represented by three capital letters (IATA code).
 *     3. You may assume all tickets form at least one valid itinerary.
 *
 * Example 1:
 *     tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 *     Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
 *
 * Example 2:
 *     tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 *     Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
 *     Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<string> findItinerary(vector<pair<string, string>> tickets) 
{
    vector<bool> visited(tickets.size(), false);
    vector<bool> used(tickets.size(), false);
    string target = "JFK", next = "";
    vector<string> result;
    while (true) {
        int i = 0, idx = 0;
        for (auto ticket: tickets) {
            if (!visited[i] && ticket.first == target) {
                visited[i] = true;
                if (next == "" || next < ticket.second) {
                    next = ticket.second;
                    idx = i;
                }
            }
            i++;
        }
        result.push_back(target);
        if (next != "") {
            target = next;
            next = "";
            used[idx] = true;
            visited.assign(used.begin(), used.end());
        } else {
            break;
        }
    }
    if (result.size() == 1) {
        return vector<string>();
    }
    return result;
}
