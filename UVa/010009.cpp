#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

map<string, int> cti;
map<int, string> itc;
vi d, pi;

void bfs(vvi &adjList, int u, int v) {
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty() && pi[v] == -1) {
        u = q.front(); q.pop();
        for (int j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];
            if (d[v] == INT_MAX) {
                pi[v] = u;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void printPath(int v) {
    if (v == -1) return;
    printPath(pi[v]);
    cout << itc[v][0];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n, V = 0;
        cti.clear();
        itc.clear();
        cin >> m >> n;
        vvi adjList(m+1, vi());
        for (int i = 0; i < m; i++) {
            string s, t;
            cin >> s >> t;
            if (cti.count(s) == 0) itc[cti[s] = V++] = s;
            if (cti.count(t) == 0) itc[cti[t] = V++] = t;
            adjList[cti[s]].push_back(cti[t]);
            adjList[cti[t]].push_back(cti[s]);
        }

        while (n--) {
            string s, t;
            cin >> s >> t;
            int u = cti[s], v = cti[t];
            d.assign(m+1, INT_MAX);
            pi.assign(m+1, -1);
            bfs(adjList, u, v);
            printPath(v);
            cout << endl;
        }

        if (T > 0) cout << endl;
    }

    return 0;
}
