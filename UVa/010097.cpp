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

int g[100][100];
int d[100][100];
int N3;

int bfs(ii u) {
    d[u.first][u.second] = 0;
    queue<ii> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front(); q.pop();
        int n1 = u.first, n2 = u.second;
        if (n1 == N3 || n2 == N3)
            return d[n1][n2];

        // move n1
        if (g[n1][n2] != -1) {
            int N1 = g[n1][n2];
            if (d[N1][n2] == INT_MAX) {
                d[N1][n2] = d[n1][n2] + 1;
                q.push(ii(N1, n2));
            }
        }

        // move n2
        if (g[n2][n1] != -1) {
            int N2 = g[n2][n1];
            if (d[n1][N2] == INT_MAX) {
                d[n1][N2] = d[n1][n2] + 1;
                q.push(ii(n1, N2));
            }
        }
    }

    return INT_MAX;
}

int main() {
    int N, T = 1;
    while (cin >> N && N != 0) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                cin >> g[i][j];
                g[i][j]--;
                d[i][j] = INT_MAX;
            }

        int N1, N2;
        cin >> N1 >> N2 >> N3;
        N1--, N2--, N3--;

        int steps = bfs(ii(N1, N2));
        printf("Game #%d\n", T++);
        if (steps == INT_MAX) cout << "Destination is Not Reachable !" << endl;
        else printf("Minimum Number of Moves = %d\n", steps);
        cout << endl;
    }

    return 0;
}