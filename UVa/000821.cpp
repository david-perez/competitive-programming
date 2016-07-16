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

int N;
int adjMat[100][100];

void floyd() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main() {
    int u, v, t = 1;
    while (cin >> u >> v && !(u == 0 && v == 0)) {
        map<int, int> m;
        N = 0;

        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++) {
                if (i == j) adjMat[i][j] = 1;
                else adjMat[i][j] = INF;
            }

        m[u] = N++;
        m[v] = N++;
        u = m[u];
        v = m[v];
        adjMat[u][v] = 1;

        while (cin >> u >> v && !(u == 0 && v == 0)) {
            if (m.count(u) > 0) u = m[u];
            else {
                m[u] = N++;
                u = m[u];
            }

            if (m.count(v) > 0) v = m[v];
            else {
                m[v] = N++;
                v = m[v];
            }

            adjMat[u][v] = 1;
        }

        floyd();

        int l = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (i != j) l += adjMat[i][j];

        printf("Case %d: average length between pages = %.3f clicks\n", t++, l / ((double) N*(N-1)));
    }

    return 0;
}