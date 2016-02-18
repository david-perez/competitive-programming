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

void bfs(vvi &adjList, int s) {
    vi d(adjList.size(), INT_MAX);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];
            if (d[v] == INT_MAX) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    sort(d.begin(), d.end());
    int M = 0, D = 0, i = 1;
    while (i < d.size() && d[i] != INT_MAX) {
        int t = d[i], boom = 0;
        while (d[i] == t) {
            boom++;
            i++;
        }
        if (boom > M) {
            M = boom;
            D = t;
        }
    }

    if (M == 0) cout << 0 << endl;
    else printf("%d %d\n", M, D);
}

int main() {
    int V;
    cin >> V;
    vvi adjList(V, vi());
    for (int u = 0; u < V; u++) {
        int N, v;
        cin >> N;
        while (N--) {
            cin >> v;
            adjList[u].push_back(v);
        }
    }

    int T, s;
    cin >> T;
    while (T--) {
        cin >> s;
        bfs(adjList, s);
    }

    return 0;
}