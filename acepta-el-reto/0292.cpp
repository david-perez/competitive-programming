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
typedef vector<id> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

void dijkstra(int s, vector<vii> &adjList, vector<ll> &dist) {
    dist.assign(adjList.size(), LONG_MAX);
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
    int N, C, O, P;
    while (cin >> N) {
        vector<vii> adjList(N, vii());
        vector<vii> adjListT(N, vii());

        cin >> C;
        while (C--) {
            int u, v, w;
            cin >> u >> v >> w; u--; v--;
            adjList[u].push_back(ii(v, w));
            adjListT[v].push_back(ii(u, w));
        }

        cin >> O >> P; O--;
        vector<ll> dist, distT;
        dijkstra(O, adjList, dist);
        dijkstra(O, adjListT, distT);

        ll cost = 0;
        bool imp = false;
        while (P--) {
            int d;
            cin >> d; d--;
            if (!imp) {
                if (dist[d] != LONG_MAX && distT[d] != LONG_MAX) cost += dist[d] + distT[d];
                else imp = true;
            }
        }

        if (!imp) cout << cost << endl;
        else cout << "Imposible" << endl;
    }

    return 0;
}