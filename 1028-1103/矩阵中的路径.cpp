/**
 * 矩阵中的路径
 * https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * 
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，
 * 向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
 * 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
 * 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
 * 路径不能再次进入该格子。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (*str == '\0' || rows == 0 || cols == 0) {
            return false;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i * cols + j] == *str) {
                    vector<bool> visited(rows * cols, false);
                    if (dfs(matrix, rows, cols, i, j, str + 1, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(char* matrix, int rows, int cols, int i, int j, char* str, vector<bool>& visited)
    {
        // cout << "DFS: i = " << i << " j = " << j << " *str = " << *str << endl;
        if (*str == '\0') {
            return true;
        }
        visited[i * cols + j] = true;
        for (auto dir: direction) {
            int ii = i + dir[0];
            int jj = j + dir[1];
            // cout << ii << " " << jj << "?" << endl;
            if (isSafe(rows, cols, ii, jj) && !visited[ii * cols + jj] && matrix[ii * cols + jj] == *str) {
                // cout << ii << " " << jj << endl;
                if (dfs(matrix, rows, cols, ii, jj, str + 1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isSafe(int rows, int cols, int i, int j) 
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
};

int main()
{
    Solution sol;
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char str[] = "SGGFIECVAASABCEHJIGQEM";
    cout << sol.hasPath(matrix, 5, 8, str) << endl;
    return 0;
}
