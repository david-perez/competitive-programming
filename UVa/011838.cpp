#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
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
typedef pair<int, int> ii;
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

void dfs(int u, vvi &adjList, vi &dfs_num, vi &topo) {
    dfs_num[u] = 1;
    for (int v = 0; v < (int) adjList[u].size(); v++)
        if (dfs_num[adjList[u][v]] == 0)
            dfs(adjList[u][v], adjList, dfs_num, topo);
    topo.push_back(u);
}

/**
 * Computes the number of strongly connected components of a directed unweighted graph.
 * @param adjList
 * @return 
 */
int kosaraju(vvi &adjList) {
    vi dfs_num; dfs_num.assign(adjList.size(), 0);
    vi topo;
    
    for (int u = 0; u < (int) adjList.size(); u++)
        if (dfs_num[u] == 0)
            dfs(u, adjList, dfs_num, topo);
    
    // compute transpose graph
    vvi adjListT; adjListT.assign(adjList.size(), vi());
    for (int u = 0; u < (int) adjList.size(); u++)
        for (int v = 0; v < (int) adjList[u].size(); v++)
            adjListT[adjList[u][v]].push_back(u);
    
    int scc = 0;
    dfs_num.assign(adjListT.size(), 0);
    for (int i = topo.size()-1; i >= 0; i--) {
        if (dfs_num[topo[i]] == 0) {
            dfs(topo[i], adjListT, dfs_num, topo);
            scc++;
        }
    }
    
    return scc;
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) && !(N == 0 && M == 0)) {
        vvi adjList; adjList.assign(N, vi());
        int u, v, p;
        while (M--) {
            cin >> u >> v >> p;
            adjList[u-1].push_back(v-1);
            if (p == 2) adjList[v-1].push_back(u-1);
        }
        
        cout << (kosaraju(adjList) == 1 ? 1 : 0) << endl;
    }
    
    return 0;
}