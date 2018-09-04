/**
 * 207. Course Schedule
 * https://leetcode.com/problems/course-schedule/description/
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you 
 * have to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, 
 * is it possible for you to finish all courses?
 *
 * Example 1:
 *     Input: 2, [[1,0]] 
 *     Output: true
 *     Explanation: There are a total of 2 courses to take. 
 *                  To take course 1 you should have finished course 0. So it is possible.
 *                  
 * Example 2:
 *     Input: 2, [[1,0],[0,1]]
 *     Output: false
 *     Explanation: There are a total of 2 courses to take. 
 *                  To take course 1 you should have finished course 0, and to take course 0 
 *                  you should also have finished course 1. So it is impossible.
 */

#include <iostream>
#include <vector>
#include <pair>
#include <queue>

using namespace std;

struct Edge {
    int target;
    Edge *next;
    Edge(int tag, Edge *n): target(tag), next(n) {};
};

struct Vertex {
    Edge *first_edge;
    Vertex(): first_edge(NULL) {};
    Vertex(Edge *edge): first_edge(edge) {};
};

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
{
    vector<Vertex> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    queue<int> Q;
    for (auto course: prerequisites) {
        Edge * edge = new Edge(course.first, graph[course.second].first_edge);
        graph[course.second].first_edge = edge;
        indegree[course.first]++;
    }
    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }
    int cnt = 0;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        cnt++;
        for (Edge *e = graph[v].first_edge; e; e = e->next) {
            if (--indegree[e->target] == 0) {
                Q.push(e->target);
            }
        }
    }
    if (cnt == numCourses) {
        return true;
    } else {
        return false;
    }
}
