#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void bfs(vector<vi> &adjList, int u, vi &d) {
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
    int E;
    cin >> E;
    vvi adjList(E, vi());
    for (int u = 0; u < E; u++) {
        int N;
        cin >> N;
        while (N--) {
            int v;
            cin >> v;
            adjList[u].push_back(v);
        }
    }

    int T;
    cin >> T;
    while (T--) {
        vi d(E, INT_MAX);
        int s;
        cin >> s;
        bfs(adjList, s, d);

        vi cnt(E, 0);
        for (int &day : d)
            if (day != INT_MAX)
                cnt[day]++;

        int M = 0;
        int D = -1;
        for (int day = 1; day < E; day++)
            if (cnt[day] > M) {
                M = cnt[day];
                D = day;
            }

        if (D == -1) cout << 0 << endl;
        else printf("%d %d\n", M, D);
    }
}