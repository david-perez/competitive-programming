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

const int MAX_V = 100;
int res[MAX_V][MAX_V];
int f;

void augment(int v, int s, int minEdge, vi &p) {
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], s, min(minEdge, res[p[v]][v]), p);
        res[p[v]][v] -= f, res[v][p[v]] += f;
    }
}

// This is a purely iterative approach of augment()
void augment2(int s, int t, vi &p) {
    int minEdge = INT_MAX;
    int v = t;
    while (p[v] != -1) {
        minEdge = min(minEdge, res[p[v]][v]);
        v = p[v];
    }

    if (v != s) {
        f = 0;
        return;
    }

    f = minEdge;
    v = t;
    while (v != s) {
        res[p[v]][v] -= f, res[v][p[v]] += f;
        v = p[v];
    }
}

int edmondKarps(vvi &adjList, int res[MAX_V][MAX_V], int s, int t) {
    int mf = 0;
    while (true) {
        f = 0;
        bitset<MAX_V> vis; vis[s] = true;
        queue<int> q; q.push(s);
        vi p(adjList.size(), -1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int j = 0; j < adjList[u].size(); j++) {
                int v = adjList[u][j];
                if (res[u][v] > 0 && !vis[v])
                    vis[v] = true, q.push(v), p[v] = u;
            }
        }
        //augment(t, s, INT_MAX, p);
        augment2(s, t, p);
        if (f == 0) break;
        mf += f;
    }
    return mf;
}

int main() {
    int n, i = 1;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = 0;

        vvi adjList(n, vi());

        int s, t, c;
        cin >> s >> t >> c; s--; t--;

        int u, v, w;
        while (c--) {
            cin >> u >> v >> w; u--; v--;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            res[u][v] += w;
            res[v][u] += w;
        }

        printf("Network %d\nThe bandwidth is %d.\n\n", i++, edmondKarps(adjList, res, s, t));
    }

    return 0;
}