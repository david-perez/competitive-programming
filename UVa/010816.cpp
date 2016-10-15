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
typedef pair<dd, int> ddi;
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

void dijkstraR(int s, vector<vector<di>> &adjList, vd &dist) {
    dist.assign(adjList.size(), INT_MAX);
    dist[s] = 0;
    priority_queue<di, vector<di>, greater<di>> pq; pq.push(di(dist[s], s));
    while (!pq.empty()) {
        di front = pq.top(); pq.pop();
        double R = front.first;
        int u = front.second;
        if (R > dist[u]) continue;
        for (int j = 0; j < adjList[u].size(); j++) {
            di v = adjList[u][j];
            if (dist[v.second] > max(R, v.first)) {
                dist[v.second] = max(R, v.first);
                pq.push(di(dist[v.second], v.second));
            }
        }
    }
}

void dijkstraD(int s, vector<vector<di>> &adjList, vector<vector<di>> &adjListR, double tMax, vd &dist, vi &pi) {
    dist.assign(adjList.size(), INT_MAX);
    pi.assign(adjList.size(), -1);
    dist[s] = 0;
    priority_queue<di, vector<di>, greater<di>> pq; pq.push(di(dist[s], s));
    while (!pq.empty()) {
        di front = pq.top(); pq.pop();
        double D = front.first;
        int u = front.second;
        if (D > dist[u]) continue;
        for (int j = 0; j < adjList[u].size(); j++) {
            di v = adjList[u][j];
            if (dist[v.second] > dist[u] + v.first && adjListR[u][j].first <= tMax) {
                dist[v.second] = dist[u] + v.first;
                pi[v.second] = u;
                pq.push(di(dist[v.second], v.second));
            }
        }
    }
}

void printPath(vi &pi, int T) {
    if (pi[T] == -1) cout << T+1;
    else {
        printPath(pi, pi[T]);
        printf(" %d", T+1);
    }
}

int main() {
    int N, E;
    while (cin >> N >> E) {
        vector<vector<di>> adjListR(N, vector<di>());
        vector<vector<di>> adjListD(N, vector<di>());
        int S, T;
        cin >> S >> T;
        S--, T--;
        while (E--) {
            int u, v;
            double R, D;
            cin >> u >> v >> R >> D;
            u--, v--;
            adjListR[u].push_back(di(R, v));
            adjListR[v].push_back(di(R, u));
            adjListD[u].push_back(di(D, v));
            adjListD[v].push_back(di(D, u));
        }

        vd dR;
        dijkstraR(S, adjListR, dR);

        vd dD;
        vi pi;
        dijkstraD(S, adjListD, adjListR, dR[T], dD, pi);

        printPath(pi, T);
        cout << endl;
        printf("%.1f %.1f\n", dD[T], dR[T]);
    }

    return 0;
}