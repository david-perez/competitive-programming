#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool bfs(vvi &adjList, int u) {
    vi d(adjList.size(), INT_MAX);
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];
            if (d[v] == INT_MAX) {
                d[v] = d[u] + 1;
                q.push(v);
            } else return false;
        }
    }

    for (int u = 0; u < adjList.size(); u++)
        if (d[u] == INT_MAX) return false;
    return true;
}

int main() {
    int u, v, k = 1;
    while (cin >> u >> v && !(u < 0 && v < 0)) {
        int V = 0;
        map<int, int> m;
        vvi adjList;
        while (!(u == 0 && v == 0)) {
            if (m.count(u) == 0) {
                m[u] = V++;
                adjList.push_back(vi());
            }
            if (m.count(v) == 0) {
                m[v] = V++;
                adjList.push_back(vi());
            }
            u = m[u], v = m[v];
            adjList[u].push_back(v);
            cin >> u >> v;
        }

        bool tree = true;
        int inDeg[V];
        for (int i = 0; i < V; i++) inDeg[i] = 0;
        for (int i = 0; i < V && tree; i++)
            for (int j = 0; j < adjList[i].size() && tree; j++) {
                if (i == adjList[i][j]) tree = false; // self-edge
                inDeg[adjList[i][j]]++;
            }

        int root = -1;
        for (int v = 0; v < V && tree; v++)
            if (root == -1 && inDeg[v] == 0) root = v;
            else if (inDeg[v] != 1) tree = false;

        tree &= root >= 0 && bfs(adjList, root);
        printf("Case %d is %sa tree.\n", k++, V == 0 || tree ? "" : "not ");
    }

    return 0;
}
