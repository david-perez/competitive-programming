#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <list>
#include <forward_list>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, ll> mll;

#define INF 1000000000 // 10^9

vvi adjList;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
vector<bool> ap;
int dfsCounter;
int rootChildren;
int dfsRoot = 0;

void apb(int u) {
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == -1) { // unvisited
            if (u == dfsRoot) rootChildren++;
            dfs_parent[v] = u;

            apb(v);

            if (dfs_low[v] >= dfs_num[u])
                ap[u] = true; // u is an articulation point
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) // back/forward edge
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        adjList.assign(N, vi());
        int u;
        while (cin >> u && u != 0) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int v;
            while (ss >> v) {
                adjList[u-1].push_back(v-1);
                adjList[v-1].push_back(u-1);
            }
        }

        dfs_num.assign(N, -1);
        dfs_low.assign(N, -1);
        dfs_parent.assign(N, -1);
        ap.assign(N, false);
        dfsCounter = rootChildren = 0;

        apb(dfsRoot);
        ap[dfsRoot] = (rootChildren > 1);

        int cnt = 0;
        for (bool b : ap)
            if (b) cnt++;

        cout << cnt << endl;
    }

    return 0;
}