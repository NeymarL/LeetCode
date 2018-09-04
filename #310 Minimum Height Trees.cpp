/**
 * 310. Minimum Height Trees
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * For a undirected graph with tree characteristics, we can choose any node as the root. 
 * The result graph is then a rooted tree. Among all possible rooted trees, those with 
 * minimum height are called minimum height trees (MHTs). Given such a graph, write a 
 * function to find all the MHTs and return a list of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be given the 
 * number n and a list of undirected edges (each edge is a pair of labels).
 * 
 * You can assume that no duplicate edges will appear in edges. Since all edges are undirected, 
 * [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */

#include <iostream>
#include <vector>
#include <pair>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<int> ans;
        queue<int> Q, newQ;
        vector<bool> visited(n, false);
        for (auto edge: edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
            indegree[edge.first]++;
            indegree[edge.second]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                Q.push(i);
            }
        }
        int cnt = n;
        while (cnt > 2) {
            // find leaves and remove them then find new leaves
            // like topological sort
            cnt -= Q.size();
            while (!Q.empty()) {
                int node = Q.front();
                Q.pop();
                visited[node] = true;
                for (int i = 0; i < graph[node].size(); i++) {
                    if (!visited[graph[node][i]]) {
                        if (--indegree[graph[node][i]] == 1) {
                            newQ.push(graph[node][i]);
                        }
                    }
                }
            }
            Q = newQ;
            newQ = queue<int>();
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }

};
