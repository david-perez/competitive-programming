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

const int MAX_V = 500 + 500 + 2;
int res[MAX_V][MAX_V];
vvi adjList;
int f, s = 0, t;

void augment(int v, int minEdge, vi &p) {
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]), p);
        res[p[v]][v] -= f, res[v][p[v]] += f;
    }
}

int edmondKarps(vvi &adjList) {
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
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int b, n;
        cin >> b >> n;
        t = b+n+1;

        adjList.assign(t+1, vi());

        for (int i = 0; i <= t; i++)
            for (int j = 0; j <= t; j++)
                res[i][j] = 0;

        for (int i = 1; i <= b; i++) {
            res[s][i] = 1;
            adjList[s].push_back(i);
            adjList[i].push_back(s);
            for (int j = 1; j <= n; j++) {
                int x;
                cin >> x;
                res[i][b + j] = x;
                if (x == 1) {
                    adjList[i].push_back(b + j);
                    adjList[b + j].push_back(i);
                }
            }
        }

        for (int j = 1; j <= n; j++) {
            res[b + j][t] = 1;
            adjList[b + j].push_back(t);
            adjList[t].push_back(b + j);
        }

        int mf = edmondKarps(adjList);
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", c, mf);
    }

    return 0;
}