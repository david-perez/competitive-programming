#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define UNVISITED -1

vvi adjList;
vi dfs_num, dfs_low, dfs_parent;
vector<bool> ap;
int dfsCounter, dfsRoot, rootChildren;

void findAp(int u) {
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;

            findAp(v);

            ap[u] = ap[u] | (dfs_low[v] >= dfs_num[u]);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[v] != u)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
    int N;
    for (int t = 1; cin >> N && N != 0; t++) {
        if (t > 1) cout << endl;
        adjList.assign(N, vi());
        vector<string> places;
        map<string, int> m;

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            places.push_back(s);
            m[s] = i;
        }

        int R;
        cin >> R;
        while (R--) {
            string s, t;
            cin >> s >> t;
            int u = m[s], v = m[t];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs_num.assign(N, UNVISITED);
        dfs_low.assign(N, 0);
        dfs_parent.assign(N, -1);
        ap.assign(N, false);
        dfsCounter = 0;
        for (dfsRoot = 0; dfsRoot < N; dfsRoot++)
            if (dfs_num[dfsRoot] == UNVISITED) {
                rootChildren = 0;
                findAp(dfsRoot);
                ap[dfsRoot] = rootChildren > 1;
            }

        set<string> cameras;
        for (int u = 0; u < N; u++)
            if (ap[u])
                cameras.insert(places[u]);

        printf("City map #%d: %d camera(s) found\n", t, cameras.size());
        for (const string &s : cameras)
            cout << s << endl;
    }

    return 0;
}
