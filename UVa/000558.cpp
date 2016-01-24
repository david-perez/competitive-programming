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
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

bool bellman_ford(int s, vector<vii> &adjList, vi &dist) {
    dist.assign(adjList.size(), INT_MAX); dist[s] = 0;
    bool relaxed;
    
    for (int i = 0; i < adjList.size(); i++) {
        relaxed = false;
        for (int u = 0; u < adjList.size(); u++)
            for (int j = 0; j < adjList[u].size(); j++) {
                ii v = adjList[u][j];
                if (dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                    relaxed = true;
                }
            }
        if (!relaxed) return false;
    }
    return relaxed; // if the last iteration relaxed some edge, the graph contains a negative cycle.
}

int main() {
    int c;
    
    cin >> c;
    while (c--) {
        int n, m;
        
        cin >> n >> m;
        vector<vii> adjList; adjList.assign(n, vii());
        
        int x, y, t;
        while (m--) {
            cin >> x >> y >> t;
            adjList[x].push_back(ii(y, t));
        }
        
        vi dist;
        cout << (bellman_ford(0, adjList, dist) ? "possible" : "not possible") << endl;
    }
    return 0;
}