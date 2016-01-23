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

/**
 * SSSP on a weighted directed graph in adjList from source vertex s.
 * @param s
 * @param adjList
 * @param dist
 */
void dijkstra(int s, vector<vii> &adjList, vi &dist) {
    dist.assign(adjList.size(), INT_MAX);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq; pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (int j = 0; j < adjList[u].size(); j++) {
            ii v = adjList[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
}

int main() {
    int N;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        
        vector<vii> adjList; adjList.assign(n, vii());
        
        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            adjList[u].push_back(ii(v, w));
            adjList[v].push_back(ii(u, w));
        }
        vi dist;
        dijkstra(S, adjList, dist);
        
        if (dist[T] == INT_MAX) printf("Case #%d: unreachable\n", i);
        else printf("Case #%d: %d\n", i, dist[T]);
    }
    
    return 0;
}