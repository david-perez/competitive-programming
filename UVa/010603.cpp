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
typedef pair<int, ii> iii;
typedef vector<iii> viii;
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

int A, B, C, D;
int d, minCost;
map<ii, int> dist;

void relax(priority_queue<iii, viii, greater<iii>> &pq, int cost, ii &state) {
    if (dist.count(state) == 0 || cost < dist[state]) {
        dist[state] = cost;
        pq.push(make_pair(dist[state], state));
    }
}

void dijkstra(ii u) {
    dist[u] = 0;
    priority_queue<iii, viii, greater<iii>> pq; pq.push(make_pair(dist[u], u));
    while (!pq.empty()) {
        iii front = pq.top(); pq.pop();
        int poured = front.first;
        int a = front.second.first;
        int b = front.second.second;
        int c = C - (a + b);

        if (dist.count(ii(a, b)) > 0 && poured > dist[ii(a, b)]) continue;

        if (a == D || b == D || c == D) {
            d = D;
            minCost = poured;
            return;
        }

        if (d < a && a < D) d = a, minCost = poured;
        if (d < b && b < D) d = b, minCost = poured;
        if (d < c && c < D) d = c, minCost = poured;

        int pour;
        ii state;

        // pour a into b
        pour = min(B - b, a);
        a -= pour;
        b += pour;
        state = ii(a, b);

        relax(pq, poured + pour, state);

        a += pour;
        b -= pour;

        // pour a into c
        pour = min(C - c, a);
        a -= pour;
        c += pour;
        state = ii(a, C - (a+c));

        relax(pq, poured + pour, state);

        a += pour;
        c -= pour;

        // pour b into a
        pour = min(A - a, b);
        b -= pour;
        a += pour;
        state = ii(a, b);

        relax(pq, poured + pour, state);

        b += pour;
        a -= pour;

        // pour b into c
        pour = min(C - c, b);
        b -= pour;
        c += pour;
        state = ii(C - (b+c), b);

        relax(pq, poured + pour, state);

        b += pour;
        c -= pour;

        // pour c into a
        pour = min(A - a, c);
        c -= pour;
        a += pour;
        state = ii(a, C - (a+c));

        relax(pq, poured + pour, state);

        c += pour;
        a -= pour;

        // pour c into b
        pour = min(B - b, c);
        c -= pour;
        b += pour;
        state = ii(C - (b+c), b);

        relax(pq, poured + pour, state);

        c += pour;
        b -= pour;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> A >> B >> C >> D;
        dist.clear();
        d = 0;
        minCost = 0;
        dijkstra(ii(0, 0));
        printf("%d %d\n", minCost, d);
    }

    return 0;
}