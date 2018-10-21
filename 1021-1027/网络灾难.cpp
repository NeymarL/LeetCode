#include <iostream>
#include <vector>

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

void cut(vector<Vertex>& graph, int a, int b)
{
    Edge* e = graph[a - 1].first_edge;
    Edge* pre = NULL;
    while (e) {
        if (e->target == b - 1) {
            if (!pre) {
                graph[a - 1].first_edge = e->next;
            } else {
                pre->next = e->next;
            }
            free(e);
            break;
        }
        pre = e;
        e = e->next;
    }
    e = graph[b - 1].first_edge;
    pre = NULL;
    while (e) {
        if (e->target == a - 1) {
            if (!pre) {
                graph[b - 1].first_edge = e->next;
            } else {
                pre->next = e->next;
            }
            free(e);
            break;
        }
        pre = e;
        e = e->next;
    }
}

void dfs(vector<Vertex>& graph, int i, vector<bool>& visited)
{
    visited[i] = true;
    for (Edge* e = graph[i].first_edge; e; e = e->next) {
        if (!visited[e->target]) {
            dfs(graph, e->target, visited);
        }
    }
}

int main()
{
    int m, n;
    cin >> n >> m;  // n：集群数目；m：光缆数目
    vector<pair<int, int>> lines(m);
    vector<int> cuts(m);
    vector<Vertex> nodes(n, Vertex());
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        lines[i].first = a;
        lines[i].second = b;
        Edge* e = new Edge(b - 1, nodes[a - 1].first_edge);
        nodes[a - 1].first_edge = e;
        e = new Edge(a - 1, nodes[b - 1].first_edge);
        nodes[b - 1].first_edge = e;
    }
    for (int i = 0; i < m; i++) {
        cin >> cuts[i];
    }
    for (int i = 0; i < m; i++) {
        cut(nodes, lines[cuts[i] - 1].first, lines[cuts[i] - 1].second);
        vector<bool> visited(n, false);
        dfs(nodes, 0, visited);
        for (int j = 0; j < n; j++) {
            if (visited[j] == false) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    cout << m << endl;
    return 0;
}
