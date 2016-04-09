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

int mod = 10000;

void push(int u, int v, int t, vi &d, queue<int> &q) {
    if (d[v] == INT_MAX) {
        d[v] = d[u] + 1;
        q.push(v);
    }
}

int bfs(int u, int t, vi &d) {
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front(); q.pop();
        int v = (u+1) % mod;
        push(u, v, t, d, q);
        if (v == t) return d[v];
        v = (u*2) % mod;
        push(u, v, t, d, q);
        if (v == t) return d[v];
        v = u/3;
        push(u, v, t, d, q);
        if (v == t) return d[v];
    }
}

int main() {
    int s, t;
    while (cin >> s >> t) {
        vi dist(mod, INT_MAX);
        cout << bfs(s, t, dist) << endl;
    }

    return 0;
}