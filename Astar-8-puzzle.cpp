/**
 * Given a 3×3 board with 8 tiles (every tile has one number from 1 to 8) and one empty space. 
 * The objective is to place the numbers on tiles to match final configuration using the empty 
 * space. We can slide four adjacent (left, right, above and below) tiles into the empty space.
 *
 *     1 2 3
 *     8   4
 *     7 6 5
 *
 * If the number of inversions is odd, then the goal state cannot be reached.
 *
 * An inversion is defined as follows:
 *     Given a board, an inversion is any pair of blocks i and j where i < j but i appears after j 
 *     when considering the board in row-major order (row 0, followed by row 1, and so forth).
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;
#define N 3

// botton, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

struct Node {
    Node* parent = NULL;
    vector<vector<int>> value;
    int g;
    int h;
    int zi;
    int zj;

    Node(Node* p, vector<vector<int>>& v, int _g, int _h): parent(p), value(v), g(_g), h(_h) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (v[i][j] == 0) {
                    zi = i; zj = j;
                    break;
                }
            }
        }
    };
};

struct comp
{
    bool operator()(const Node* a, const Node* b) const
    {
        if (a->g + a->h == b->g + b->g) {
            return a->g > b->g;
        }
        return a->g + a->h > b->g + b->h;
    }
};

void print_matrix(vector<vector<int>>& mat)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_path(Node* node)
{
    if (node == NULL) {
        return;
    }
    print_path(node->parent);
    print_matrix(node->value);
}

int heuristic(vector<vector<int>>& mat)
{
    vector<vector<int>> goal = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}}; // 3x3
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] != goal[i][j] && mat[i][j] != 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

string serialize(vector<vector<int>>& mat)
{
    string s = "";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            s += to_string(mat[i][j]);
        }
    }
    return s;
}

bool is_safe(int i, int j)
{
    if (i >= 0 && i < N && j >= 0 && j < N) {
        return true;
    }
    return false;
}

vector<vector<int>> swap(vector<vector<int>>& initial, int i0, int j0, int i1, int j1)
{
    vector<vector<int>> tmp(initial);
    int t = tmp[i0][j0];
    tmp[i0][j0] = tmp[i1][j1];
    tmp[i1][j1] = t;
    return tmp;
}

void A_star_search(vector<vector<int>>& initial)
{
    priority_queue<Node*, vector<Node*>, comp> open;
    set<string> ancestors;

    bool success = false;

    Node* T = new Node(NULL, initial, 0, heuristic(initial));
    open.push(T);
    ancestors.insert(serialize(T->value));

    while (!open.empty()) {
        Node* node = open.top();
        open.pop();
        // reach the goal?
        if (node->h == 0) {
            print_path(node);
            cout << node->g << endl;
            success = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            if (is_safe(node->zi + row[i], node->zj + col[i])) {
                vector<vector<int>> v = swap(node->value, node->zi, node->zj,
                                             node->zi + row[i], node->zj + col[i]);
                string s = serialize(v);
                if (ancestors.find(s) == ancestors.end()) {
                    ancestors.insert(s);
                    Node* child = new Node(node, v, node->g + 1, heuristic(v));
                    open.push(child);
                }
            }
        }
    }
    if (!success)
        cout << "Mission Failed" << endl;
}

int main()
{
    vector<vector<int>> initial = {{8, 6, 7}, {2, 5, 1}, {3, 0, 4}};
    A_star_search(initial);
    return 0;
}
