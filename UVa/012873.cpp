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

int s = 0, t, f;
const int MAX_V = 500 + 20 + 2;
int res[MAX_V][MAX_V];
vvi adjList;

void augment(int v, int minEdge, vi &p) {
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]), p);
        res[p[v]][v] -= f, res[v][p[v]] += f;
    }
}

int edmondKarps() {
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
        augment(t, INT_MAX, p);
        if (f == 0) break;
        mf += f;
    }
    return mf;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int P, S, C, m;
        cin >> P >> S >> C >> m;
        int V = P + S + 2;
        t = V - 1;
        adjList.assign(V, vi());

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                res[i][j] = 0;

        while (m--) {
            int u, v;
            cin >> u >> v;
            v += P;
            res[u][v] = 1;
            res[s][u] = 1;
            res[v][t] = C;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            adjList[s].push_back(u);
            adjList[u].push_back(s);
            adjList[v].push_back(t);
            adjList[t].push_back(v);
        }

        cout << edmondKarps() << endl;
    }

    return 0;
}