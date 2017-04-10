#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define UNVISITED -1

vvi adjList;
set<ii> bridges;
vi dfs_num, dfs_low, dfs_parent;
int dfsCounter;

void findBridges(int u) {
    dfs_low[u] = dfs_num[u] = dfsCounter++;

    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];

        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            findBridges(v);

            if (dfs_low[v] > dfs_num[u])
                bridges.insert(ii(min(u, v), max(u, v)));
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) // a back edge
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
    int n;
    while (cin >> n) {
        adjList.assign(n, vi());
        cin.get();

        for (int i = 0; i < n; i++) {
            int u, edges;
            scanf("%d (%d) ", &u, &edges);

            while (edges--) {
                int v;
                cin >> v;
                adjList[u].push_back(v);
            }
        }

        dfsCounter = 0;
        dfs_num.assign(n, UNVISITED); dfs_low.assign(n, 0); dfs_parent.assign(n, 0);
        bridges.clear();

        for (int u = 0; u < n; u++)
            if (dfs_num[u] == UNVISITED)
                findBridges(u);

        printf("%d critical links\n", bridges.size());
        for (auto &p : bridges)
            printf("%d - %d\n", p.first, p.second);
        cout << endl;
    }

    return 0;
}