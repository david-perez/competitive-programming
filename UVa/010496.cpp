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

int dist[11][11];
int memo[11][2048]; // 11 * 2^11 states
int n;

int tsp(int pos, bitset<11> &vis) {
    int v = vis.to_ulong();
    if (v == (1 << n) - 1) return dist[pos][0];
    if (memo[pos][v] != INT_MAX) return memo[pos][v];

    for (int j = 0; j < n; j++)
        if (j != pos && vis[j] == 0) {
            vis[j] = 1;
            memo[pos][v] = min(memo[pos][v], dist[pos][j] + tsp(j, vis));
            vis[j] = 0;
        }

    return memo[pos][v];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y; cin >> x >> y >> x >> y; // max dimensions of coords are not used
        cin >> n; n++;
        vii coords(n, ii());
        coords[0] = ii(x, y);
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            coords[i] = ii(x, y);
        }

        // calculate dist matrix; the diagonal will have -1
        memset(dist, -1, sizeof dist);
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                dist[i][j] = dist[j][i] = abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second); // L^1-norm dist

        fill_n(*memo, 11*2048, INT_MAX);
        bitset<11> vis(1); // first city is already visited
        printf("The shortest path has length %d\n", tsp(0, vis));
    }

    return 0;
}