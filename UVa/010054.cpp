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

//vi dfs_num;

int adjMat[50][50];
vi deg; // vertex -> number of edges incident with vertex
vi cyc; // contains eulerian tour

int start;

void dfs(int u){
    for (int v = 0; v < 50; v++)
        if (adjMat[u][v] > 0){
            adjMat[u][v]--;
            adjMat[v][u]--;
            dfs(v);
        }
    cyc.push_back(u);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int E;
        cin >> E;
        memset(adjMat, 0, sizeof adjMat);
        deg.assign(50, 0);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adjMat[u][v]++;
            adjMat[v][u]++;
            deg[u]++;
            deg[v]++;
            start = u;
        }

        printf("Case #%d\n", t);

        bool eulerian = all_of(deg.begin(), deg.end(), [](int d){
            return d % 2 == 0;
        });

        if (!eulerian) cout << "some beads may be lost" << endl;
        else {
            cyc.clear();
            dfs(start);
            for (int i = 0; i < cyc.size()-1; i++)
                printf("%d %d\n", cyc[i] + 1, cyc[i+1] + 1);
        }

        if (T > 0) cout << endl;
    }

    return 0;
}