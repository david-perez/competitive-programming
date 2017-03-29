#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000000 // 10^9

bool bellman_ford(int s, vector<vii> &adjList, vi &dist, vi &relax) {
    dist.assign(adjList.size(), INF); dist[s] = 0;
    relax.assign(adjList.size(), 0);
    bool relaxed;
    for (int i = 0; i < adjList.size(); i++) {
        for (int u = 0; u < adjList.size(); u++)
            for (int j = 0; j < adjList[u].size(); j++) {
                ii v = adjList[u][j];
                if (dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                    relaxed = true;
                    if (i == adjList.size() - 1) relax[v.first] = 1;
                }
            }
        if (!relaxed) return false;
    }
    return relaxed;
}

void find_cycles(vector<vii> &adjList, vi &relax) {
    vi visited(adjList.size(), 0);
    queue<int> q;
    for (int i = 0; i < adjList.size(); i++)
        if (relax[i] && !visited[i]) {
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (!visited[u]) {
                    visited[u] = 1;
                    relax[u] = 1;
                    for (int j = 0; j < adjList[u].size(); j++)
                        q.push(adjList[u][j].first);
                }
            }
        }
}

int main() {
    int n, b[200];
    for (int t = 1; cin >> n; t++) {
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<vii> adjList(n, vii());
        int r;
        cin >> r;
        while (r--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adjList[u].push_back(ii(v, (b[v] - b[u])*(b[v] - b[u])*(b[v] - b[u])));
        }

        printf("Set #%d\n", t);

        vi dist, relax;
        if (adjList.size() > 0 && bellman_ford(0, adjList, dist, relax))
            find_cycles(adjList, relax);
        int q;
        cin >> q;
        while (q--) {
            int d;
            cin >> d;
            d--;

            if (relax[d] || dist[d] < 3 || dist[d] > INF - (200*20*20*20)) cout << '?' << endl;
            else cout << dist[d] << endl;
        }
    }

    return 0;
}