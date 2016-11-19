#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void bfs(vvi &adjList, int s, int t, vi &d, vi &pi) {
    pi[s] = -1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];
            if (d[v] == INT_MAX) {
                d[v] = d[u] + 1;
                pi[v] = u;
                if (v == t) return;
                q.push(v);
            }
        }
    }
}

void printPath(int u, vi &pi, map<int, string> &n) {
    if (pi[u] == -1) return;
    else {
        printPath(pi[u], pi, n);
        printf("%s %s\n", n[pi[u]].c_str(), n[u].c_str());
    }
}

int main() {
    int E;
    for (int t = 1; cin >> E; t++) {
        if (t > 1) cout << endl;

        vvi adjList;
        map<string, int> m;
        map<int, string> n;
        int ms = 0;
        while (E--) {
            string s1, s2;
            cin >> s1 >> s2;

            int u, v;
            if (m.count(s1) == 0) {
                u = ms;
                adjList.push_back(vi());
                n[ms] = s1;
                m[s1] = ms;
                ms++;
            } else u = m[s1];

            if (m.count(s2) == 0) {
                v = ms;
                adjList.push_back(vi());
                n[ms] = s2;
                m[s2] = ms;
                ms++;
            } else v = m[s2];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        string s1, s2;
        cin >> s1 >> s2;
        if (m.count(s1) == 0 || m.count(s2) == 0) { // The source or/and the destination city is/are disconnected.
            cout << "No route" << endl;
            continue;
        }

        vi d(ms, INT_MAX);
        vi pi(ms, -1);
        bfs(adjList, m[s1], m[s2], d, pi);

        if (d[m[s2]] == INT_MAX) cout << "No route" << endl;
        else printPath(m[s2], pi, n);
    }

    return 0;
}