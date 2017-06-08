#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vvi adjList;
vi d;

int dfs(int u) {
    d[u] = 1;
    int ccSize = 1;
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (d[v] == -1) ccSize += dfs(v);
    }
    return ccSize;
}

int main() {
    int T;
    cin >> T;
    cin.get();
    while (T--) {
        int V = 0;
        map<char, int> m;
        vii edgeList;
        string s;
        while (getline(cin, s) && s[0] != '*') {
            stringstream ss(s);
            ss >> s;
            char x = s[1], y = s[3];
            int u, v;
            if (m.count(x) > 0) u = m[x];
            else {
                u = V++;
                m[x] = u;
            }
            if (m.count(y) > 0) v = m[y];
            else {
                v = V++;
                m[y] = v;
            }
            edgeList.push_back(ii(u, v));
        }

        getline(cin, s);
        for (int i = 0; i < s.length(); i += 2)
            if (m.count(s[i]) == 0) m[s[i]] = V++;

        adjList.assign(V, vi());
        for (ii &e : edgeList) {
            int u = e.first, v = e.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int cc = 0, acorns = 0;
        d.assign(V, -1);
        for (int u = 0; u < V; u++)
            if (d[u] == -1) {
                if (dfs(u) == 1) acorns++;
                else cc++;
            }

        printf("There are %d tree(s) and %d acorn(s).\n", cc, acorns);
    }

    return 0;
}
