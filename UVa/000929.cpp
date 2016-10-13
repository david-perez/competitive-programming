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

int N, M;
int g[999][999];
int dist[999][999];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void dijkstra(ii s) {
    dist[s.first][s.second] = g[s.first][s.second];
    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
    pq.push(make_pair(dist[s.first][s.second], s));
    while (!pq.empty()) {
        auto front = pq.top(); pq.pop();
        int d = front.first;
        ii u = front.second;
        if (d > dist[u.first][u.second]) continue;
        for (int j = 0; j < 4; j++) {
            ii v = ii(u.first + dr[j], u.second + dc[j]);
            if (v.first < 0 || v.first >= N || v.second < 0 || v.second >= M) continue; // invalid position
            if (dist[u.first][u.second] + g[v.first][v.second] < dist[v.first][v.second]) {
                dist[v.first][v.second] = dist[u.first][u.second] + g[v.first][v.second];
                pq.push(make_pair(dist[v.first][v.second], v));
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                cin >> g[i][j];
                dist[i][j] = INT_MAX;
            }

        dijkstra(ii(0, 0));
        cout << dist[N-1][M-1] << endl;
    }

    return 0;
}