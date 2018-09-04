/**
 * 210. Course Schedule II
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you 
 * have to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, 
 * return the ordering of courses you should take to finish all courses.
 * There may be multiple correct orders, you just need to return one of them. 
 * If it is impossible to finish all courses, return an empty array.
 *
 * Example 1:
 *     Input: 2, [[1,0]] 
 *     Output: [0,1]
 *                  
 * Example 2:
 *     Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 *     Output: [0,1,2,3] or [0,2,1,3]
 */

#include <iostream>
#include <vector>
#include <pair>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
{
    vector<vector<int>> graph(numCourses);
    vector<int> ans, indegree(numCourses, 0);
    int cnt = 0;
    queue<int> Q;
    for (auto course: prerequisites) {
        graph[course.second].push_back(course.first);
        indegree[course.first]++;
    }
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        cnt++;
        ans.push_back(v);
        for (int vex: graph[v]) {
            if (--indegree[vex] == 0) {
                Q.push(vex);
            }
        }
    }
    if (cnt == numCourses) {
        return ans;
    } else {
        return vector<int>();
    }
}