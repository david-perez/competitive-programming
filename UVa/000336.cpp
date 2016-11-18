#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int bfs(vvi &adjList, int u, vi &d) {
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
            }
        }
    }
}

int main() {
    int NC, t = 1;
    while (cin >> NC && NC != 0) {
        vvi adjList(30, vi());
        map<int, int> m;
        int ms = 0;
        while (NC--) {
            int u, v;
            cin >> u >> v;

            if (m.count(u) == 0) {
                m[u] = ms;
                u = ms++;
            } else u = m[u];

            if (m.count(v) == 0) {
                m[v] = ms;
                v = ms++;
            } else v = m[v];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int s, ttl;
        while (cin >> s >> ttl && !(s == 0 && ttl == 0)) {
            vi d(ms, INT_MAX);
            bfs(adjList, m[s], d);

            int unreachable = 0;
            for (int &dist : d)
                if (dist > ttl) unreachable++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", t++, unreachable, s, ttl);
        }
    }

    return 0;
}