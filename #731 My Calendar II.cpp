/**
 * 731. My Calendar II
 * https://leetcode.com/problems/my-calendar-ii/description/
 *
 * Implement a MyCalendarTwo class to store your events. A new event can be added if adding the 
 * event will not cause a triple booking.
 * 
 * Your class will have one method, book(int start, int end). Formally, this represents a booking 
 * on the half open interval [start, end), the range of real numbers x such that start <= x < end.
 * 
 * A triple booking happens when three events have some non-empty intersection (ie., there is some 
 * time that is common to all 3 events.)
 * 
 * For each call to the method MyCalendar.book, return true if the event can be added to the calendar 
 * successfully without causing a triple booking. Otherwise, return false and do not add the event to 
 * the calendar.
 * 
 * Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
 */

#include <iostream>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class MyCalendarTwo {
public:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b)const{return a.second <= b.first; }
    };
  
    multiset<pair<int, int>> s;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        auto inv = make_pair(start, end); 
         set<pair<int, int>, cmp> s1; 
         for (auto it =s.begin(); it!=s.end();++it) {
             auto new_start=max(it->first, start), new_end= min(end, it->second);
            if(new_start < new_end)
             { 
                auto overlapped =make_pair(new_start,new_end);             
                if(s1.find(overlapped)!=s1.end()) return false;
                s1.insert(overlapped);
            }
        }
        s.insert(inv); 
        return true;
    }
};
