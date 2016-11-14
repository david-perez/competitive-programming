#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adjList;
vi pi, d;

void bfs(int s, int t) {
    d[s] = 0;
    pi[s] = -1;
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

void printPath(int t) {
    if (pi[t] == -1) cout << t+1;
    else {
        printPath(pi[t]);
        printf(" %d", t+1);
    }
}

int main() {
    int n;
    while (cin >> n) {
        adjList.assign(n, vi());
        for (int i = 0; i < n; i++) {
            int u;
            cin >> u; u--;
            cin.get(); // skip the hyphen
            string s;
            getline(cin, s);
            stringstream ss(s);
            string token;
            while (getline(ss, token, ',')) { // split the comma separated list
                int v = stoi(token); v--;
                adjList[u].push_back(v);
            }
        }

        int m;
        cin >> m;
        cout << "-----" << endl;
        while (m--) {
            int s, t;
            cin >> s >> t;
            s--, t--;

            d.assign(n, INT_MAX);
            pi.assign(n, -1);
            bfs(s, t);

            if (d[t] == INT_MAX) cout << "connection impossible" << endl;
            else {
                printPath(t);
                cout << endl;
            }
        }
    }

    return 0;
}