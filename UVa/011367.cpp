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
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
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
#define PI acos(-1)
#define EPS 1e-9

map<ii, int> dist; // cheapest trip from s to (city, fuel)

int dijkstra(ii s, int e, int c, vector<vii> &adjList, vi &p) {
    dist[s] = 0;
    priority_queue<iii, viii, greater<iii>> pq; pq.push(make_pair(0, s));
    while (!pq.empty()) {
        iii front = pq.top(); pq.pop();
        int d = front.first; // the price paid to get to u
        int u = front.second.first;

        if (u == e) return d;

        int f = front.second.second; // the available fuel
        if (dist.count(ii(u, f)) > 0 && d > dist[ii(u, f)]) continue;

        if (f < c)
            pq.push(make_pair(d + p[u], ii(u, f+1))); // stay in the same city and pay for one unit of fuel.

        for (int j = 0; j < adjList[u].size(); j++) {
            ii v = adjList[u][j];
            bool visited = dist.count(ii(v.second, f - v.first)) > 0;
            if (f - v.first >= 0 && (!visited || dist[ii(v.second, f - v.first)] > d)) {
                dist[ii(v.second, f - v.first)] = d;
                pq.push(make_pair(dist[ii(v.second, f - v.first)], ii(v.second, f - v.first)));
            }
        }
    }

    return INT_MAX;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vii> adjList(n, vii());
    vi p;

    while (n--) {
        int x;
        cin >> x;
        p.push_back(x);
    }

    while (m--) {
        int u, v, d;
        cin >> u >> v >> d;
        adjList[u].push_back(ii(d, v));
        adjList[v].push_back(ii(d, u));
    }

    int q;
    cin >> q;
    while (q--) {
        int c, s, e;
        cin >> c >> s >> e;
        dist.clear();
        int minPrice = dijkstra(ii(s, 0), e, c, adjList, p);
        if (minPrice == INT_MAX) cout << "impossible" << endl;
        else cout << minPrice << endl;
    }

    return 0;
}