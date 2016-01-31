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
    
    while (scanf("%d", &N) == 1) {
        vi weights; weights.assign(N, 0);
        for (int i = 0; i < N; i++)
            cin >> weights[i];
        
        vector<vii> adjList; adjList.assign(N, vii());
        int M, u, v, w;
        
        cin >> M;
        while (M--) {
            cin >> u >> v >> w;
            adjList[u-1].push_back(ii(v-1, w + weights[u-1]));
        }
        
        vi dist;
        dijkstra(0, adjList, dist);
        
        if (dist[N-1] == INT_MAX) cout << "IMPOSIBLE" << endl;
        else cout << dist[N-1] + weights[N-1] << endl;
    }
}