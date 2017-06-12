#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int UNVISITED = -1;
vi S;
vvi adjList, sccs;
int dfsCounter, dfs_num[25], dfs_low[25], cur_scc[25];

void tarjanSCC(int u) {
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    cur_scc[u] = 1;
    S.push_back(u);

    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (cur_scc[v] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        vi scc;
        while (true) {
            int v = S.back(); S.pop_back();
            cur_scc[v] = 0;
            scc.push_back(v);
            if (u == v) break;
        }
        sccs.push_back(scc);
    }
}

int main() {
    int n, m;
    for (int T = 1; cin >> n >> m && !(n == 0 && m == 0); T++) {
        if (T > 1) cout << endl;
        adjList.assign(n, vi());
        map<string, int> sti;
        map<int, string> its;
        int V = 0;
        while (m--) {
            string s, t;
            cin >> s >> t;
            int u, v;
            if (sti.count(s)) u = sti[s];
            else {
                u = V++;
                sti[s] = u;
                its[u] = s;
            }

            if (sti.count(t)) v = sti[t];
            else {
                v = V++;
                sti[t] = v;
                its[v] = t;
            }

            adjList[u].push_back(v);
        }

        fill(dfs_num, dfs_num + n, UNVISITED);
        fill(cur_scc, cur_scc + n, 0);
        sccs.clear();
        S.clear();
        dfsCounter = 0;
        for (int u = 0; u < n; u++)
            if (dfs_num[u] == UNVISITED)
                tarjanSCC(u);

        printf("Calling circles for data set %d:\n", T);
        for (int i = 0; i < sccs.size(); i++) {
            cout << its[sccs[i][0]];
            for (int j = 1; j < sccs[i].size(); j++)
                printf(", %s", its[sccs[i][j]].c_str());
            cout << endl;
        }
    }

    return 0;
}
