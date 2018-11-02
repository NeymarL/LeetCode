/**
 * 机器人的运动范围
 * https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 * 
 * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
 * 但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 * 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0) {
            return 0;
        }
        vector<bool> visited(rows * cols, false);
        return dfs(rows, cols, 0, 0, visited, threshold);
    }

    int dfs(int rows, int cols, int i, int j, vector<bool>& visited, int threshold)
    {
        visited[i * cols + j] = true;
        int cnt = 1;
        for (auto dir: direction) {
            int ii = i + dir[0];
            int jj = j + dir[1];
            if (isSafe(rows, cols, ii, jj) && !visited[ii * cols + jj] && isLegal(ii, jj, threshold)) {
                cnt += dfs(rows, cols, ii, jj, visited, threshold);
            }
        }
        return cnt;
    }

    bool isSafe(int rows, int cols, int i, int j) 
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

    bool isLegal(int i, int j, int threshold)
    {
        int cnt = 0;
        while (i) {
            cnt += i % 10;
            i /= 10;
        }
        while (j) {
            cnt += j % 10;
            j /= 10;
        }
        if (cnt > threshold) {
            return false;
        }
        return true;
    }
};
