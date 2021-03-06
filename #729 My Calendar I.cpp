/**
 * 729. My Calendar I
 * https://leetcode.com/problems/my-calendar-i/description/
 *
 * Implement a MyCalendar class to store your events. A new event can be added if 
 * adding the event will not cause a double booking.
 * 
 * Your class will have the method, book(int start, int end). Formally, this represents 
 * a booking on the half open interval [start, end), the range of real numbers x such 
 * that start <= x < end.
 * 
 * A double booking happens when two events have some non-empty intersection (ie., there 
 * is some time that is common to both events.)
 * 
 * For each call to the method MyCalendar.book, return true if the event can be added to 
 * the calendar successfully without causing a double booking. Otherwise, return false 
 * and do not add the event to the calendar.
 * 
 * Your class will be called like this: 
 *     MyCalendar cal = new MyCalendar(); 
 *     MyCalendar.book(start, end);
 *
 * Example 1:
 *     MyCalendar();
 *     MyCalendar.book(10, 20); // returns true
 *     MyCalendar.book(15, 25); // returns false
 *     MyCalendar.book(20, 30); // returns true
 *
 * Note:
 *     The number of calls to MyCalendar.book per test case will be at most 1000.
 *     In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
 */

#include <iostream>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class MyCalendar {
public:
    deque<pair<int, int>> events;
    int _min = 1000000000, _max = 0;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (end <= _min) {
            _min = start;
            _max = max(_max, end);
            events.push_front(make_pair(start, end));
            return true;
        }
        if (start >= _max) {
            _max = end;
            _min = min(_min, start);
            events.push_back(make_pair(start, end));
            return true;
        }
        for (auto it = events.begin(); it < events.end(); it++) {
            if (end <= it->first) {
                events.insert(it, make_pair(start, end));
                return true;
            }
            if (start >= it->second) {
                continue;
            }
            return false;
        }
    }
};

