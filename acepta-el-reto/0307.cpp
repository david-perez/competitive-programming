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

void dfs(int u, vvi &adjList, vi &dfs_num) {
    dfs_num[u] = 1;
    for (int v = 0; v < (int) adjList[u].size(); v++)
        if (dfs_num[adjList[u][v]] == 0)
            dfs(adjList[u][v], adjList, dfs_num);
}

int main() {
    int V;
    while (cin >> V) {
        vvi adjList(V);
        int A;
        cin >> A;
        for (int i = 0; i < A; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vi dfs_num(V, 0);
        dfs(0, adjList, dfs_num);

        bool conexo = true;
        for (int vis_v : dfs_num)
            if (vis_v == 0) {
                conexo = false;
                break;
            }

        // Un grafo no dirigido conexo es acíclico iff es un árbol iff |A| = |V| - 1.
        cout << (conexo && A == V - 1 ? "SI" : "NO") << endl;
    }

    return 0;
}