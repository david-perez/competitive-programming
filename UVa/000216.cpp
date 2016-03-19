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

double DOUBLE_MAX = numeric_limits<double>::max();
double dist[8][8];
double memo[8][256]; // 8 * 2^8 states
int nxtc[8][256];
int n;

double tsp(int pos, bitset<8> &vis) {
    int v = vis.to_ulong();
    if (v == (1 << n) - 1) return 0;
    if (memo[pos][v] != DOUBLE_MAX) return memo[pos][v];

    for (int j = 0; j < n; j++) {
        if (j != pos && vis[j] == 0) {
            vis[j] = 1;
            double pDist = dist[pos][j] + tsp(j, vis);
            if (pDist < memo[pos][v]) {
                memo[pos][v] = pDist;
                nxtc[pos][v] = j;
            }
            vis[j] = 0;
        }
    }

    return memo[pos][v];
}

int main() {
    int t = 1;
    while (cin >> n && n != 0) {
        vii computers;
        memset(dist, 0, sizeof dist);
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            computers.push_back(ii(x, y));
            for (int j = 0; j < i; j++)
                dist[j][i] = dist[i][j] = hypot(abs(computers[i].second - computers[j].second), abs(computers[i].first - computers[j].first));
        }

        fill_n(*memo, 8*256, DOUBLE_MAX);
        fill_n(*nxtc, 8*256, -1);
        int start = -1; double minDist = DOUBLE_MAX;
        for (int i = 0; i < n; i++) {
            bitset<8> vis; vis[i] = 1; // start at computer i
            double dist = tsp(i, vis);
            if (dist < minDist) {
                minDist = dist;
                start = i;
            }
        }

        cout << "**********************************************************" << endl;
        printf("Network #%d\n", t++);
        bitset<8> vis; vis[start] = 1; int prev = start;
        for (int i = 0; i < n-1; i++) {
            int nxt = nxtc[prev][vis.to_ulong()];
            printf("Cable requirement to connect (%d, %d) to (%d, %d) is %.2f feet.\n", computers[prev].first, computers[prev].second, computers[nxt].first, computers[nxt].second, dist[prev][nxt] + 16);
            prev = nxt;
            vis[prev] = 1;
        }
        printf("Number of feet of cable required is %.2f.\n", minDist + 16*(n-1));
    }

    return 0;
}