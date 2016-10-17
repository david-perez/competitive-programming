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

int R, C;
int g[200][200];
int dist[200][200];

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void bfs(ii u) {
    dist[u.first][u.second] = 0;
    queue<ii> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int j = 0; j < 4; j++) {
            ii v = ii(u.first + dr[j], u.second + dc[j]);
            if (v.first < 0 || v.first >= R || v.second < 0 || v.second >= C || g[v.first][v.second] == 0) continue;

            if (dist[v.first][v.second] == INT_MAX) {
                dist[v.first][v.second] = dist[u.first][u.second] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    while (cin >> R >> C && !(R == 0 && C == 0)) {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                g[i][j] = 1;
                dist[i][j] = INT_MAX;
            }

        int m;
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x][y] = 0;
        }

        int n;
        cin >> n;
        while (n--) {
            int x, y, L;
            cin >> x >> y >> L;
            x--, y--;
            int i0 = max(0, x - L);
            int j0 = max(0, y - L);
            int i1 = min(R-1, x + L);
            int j1 = min(C-1, y + L);
            for (int k0 = i0; k0 <= i1; k0++)
                for (int k1 = j0; k1 <= j1; k1++)
                    if (hypot(k1 - y, k0 - x) <= L)
                        g[k0][k1] = 0;
        }

        bfs(ii(0, 0));
        if (dist[R-1][C-1] == INT_MAX) cout << "Impossible." << endl;
        else cout << dist[R-1][C-1] << endl;
    }

    return 0;
}