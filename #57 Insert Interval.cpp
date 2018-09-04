/**
 * 57. Insert Interval
 * https://leetcode.com/problems/insert-interval/description/
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * 
 *     Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 *     Output: [[1,5],[6,9]]
 *     
 * Example 2:
 *     Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 *     Output: [[1,2],[3,10],[12,16]]
 *     Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int start = -1;
        vector<Interval> ans(intervals);
        if (intervals.empty()) {
            ans.push_back(newInterval);
            return ans;
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (start == -1) {
                if (intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.start) {
                    start = i;
                } else if (newInterval.end < intervals[i].start) {
                    ans.insert(ans.begin() + i, newInterval);
                    break;
                } else if (newInterval.start < intervals[i].start) {
                    start = i;
                    ans[i].start = newInterval.start;
                }
            }
            if (start != -1) {
                if (newInterval.end < intervals[i].start) {
                    if (i >= start + 1) {
                        ans.erase(ans.begin() + start + 1, ans.begin() + i);
                    }
                    ans[start].end = newInterval.end;
                    break;
                }
                if (newInterval.end <= intervals[i].end) {
                    if (i >= start + 1) {
                        ans.erase(ans.begin() + start + 1, ans.begin() + i + 1);
                    }
                    ans[start].end = intervals[i].end;
                    break;
                }
                if (i == intervals.size() - 1) {
                    if (i >= start + 1) {
                        ans.erase(ans.begin() + start + 1, ans.begin() + i + 1);
                    }
                    ans[start].end = newInterval.end;
                    break;
                }
            }
            if (i == intervals.size() - 1 && start == -1) {
                ans.push_back(newInterval);
            }
        }
        return ans;
    }
};