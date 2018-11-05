/**
 * 37. Sudoku Solver
 * https://leetcode.com/problems/sudoku-solver/
 * 
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 *      Each of the digits 1-9 must occur exactly once in each row.
 *      Each of the digits 1-9 must occur exactly once in each column.
 *      Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 * 
 * Empty cells are indicated by the character '.'.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solver(board);
    }

    bool solver(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isLegal(board, i, j, k)) {
                            board[i][j] = k;
                            if (solver(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isLegal(vector<vector<char>>& board, int m, int n, char val)
    {
        for (int i = 0; i < 9; i++) {
            if (board[i][n] == val) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) {
            if (board[m][j] == val) {
                return false;
            }
        }
        int row = (m / 3) * 3;
        int col = (n / 3) * 3;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
};
