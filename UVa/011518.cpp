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

vvi adjList;
vi dfs_num;

void dfs(int u) {
    dfs_num[u] = 1;
    for (int v = 0; v < adjList[u].size(); v++)
        if (dfs_num[adjList[u][v]] == 0)
            dfs(adjList[u][v]);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, l;
        cin >> n >> m >> l;

        adjList.assign(n, vi());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adjList[u].push_back(v);
        }

        dfs_num.assign(n, 0);
        for (int k = 0; k < l; k++) {
            int z;
            cin >> z;
            z--;
            if (dfs_num[z] == 0)
                dfs(z);
        }

        cout << count(dfs_num.begin(), dfs_num.end(), 1) << endl;
    }

    return 0;
}