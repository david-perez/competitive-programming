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
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<pair<int, double>> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

bool kahn(vvi &adjList, vi &topo) {
    vi inDeg(adjList.size(), 0);
    
    for (int u = 0; u < adjList.size(); u++)
        for (int v = 0; v < adjList[u].size(); v++)
            inDeg[adjList[u][v]]++;
    
    queue<int> q;
    for (int u = 0; u < inDeg.size(); u++)
        if (inDeg[u] == 0) q.push(u);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v = 0; v < adjList[u].size(); v++)
            if (--inDeg[adjList[u][v]] == 0) q.push(adjList[u][v]);
    }
    
    for (int u = 0; u < inDeg.size(); u++)
        if (inDeg[u] != 0) return true;
    return false;
}

int main() {
    int N, n, v;
    
    int t = 0;
    while (cin >> N) {
        if (t) cout << endl;
        vvi adjList(N, vi());
        for (int u = 0; u < N; u++) {
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> v;
                adjList[u].push_back(v);
            }
        }
        
        vi topo; kahn(adjList, topo);
        vi ways(adjList.size(), 0); ways[topo[0]] = 1;
        int maxWays = 0;
        
        for (int u = 0; u < topo.size(); u++) {
            if (adjList[topo[u]].size() == 0) maxWays += ways[topo[u]]; // this node is a death
            for (int v = 0; v < adjList[topo[u]].size(); v++)
                ways[adjList[topo[u]][v]] += ways[topo[u]];
        }
        
        cout << maxWays << endl;
        t++;
    }
    
    return 0;
}