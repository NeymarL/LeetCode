/**
 * 836. Rectangle Overlap
 * https://leetcode.com/problems/rectangle-overlap/
 *
 * A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the 
 * coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its 
 * top-right corner.
 * 
 * Two rectangles overlap if the area of their intersection is positive.  
 * To be clear, two rectangles that only touch at the corner or edges do not overlap.
 * 
 * Given two (axis-aligned) rectangles, return whether they overlap.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        return (max(rec1[0], rec2[0]) < min(rec1[2], rec2[2])) &&
            (max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]));
    }

    bool solution(vector<int>& rec1, vector<int>& rec2, bool first)
    {
        if ((rec2[0] > rec1[0] && rec2[0] < rec1[2]) || (rec2[2] > rec1[0] && rec2[2] < rec1[2])) {
            if ((rec2[1] > rec1[1] && rec2[1] < rec1[3]) || (rec2[3] > rec1[1] && rec2[3] < rec1[3]) ||
                (rec2[1] < rec1[3] && rec2[3] >= rec1[3]) || (rec2[1] <= rec1[1] && rec2[3] > rec1[1])) {
                return true;
            }
        }
        if (first) {
            vector<int> tmp = rec1;
            rec1 = rec2;
            rec2 = tmp;
            return solution(rec1, rec2, false);
        }
        return false;
    }
};
