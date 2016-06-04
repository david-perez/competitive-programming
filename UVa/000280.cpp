#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
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

void dfs(int u, vvi &adjList, vi &dfs_num) {
    dfs_num[u] = 1;
    for (int v = 0; v < (int) adjList[u].size(); v++)
        if (dfs_num[adjList[u][v]] == 0)
            dfs(adjList[u][v], adjList, dfs_num);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vvi adjList(n, vi());
        int u, v;
        while (cin >> u && u != 0)
            while (cin >> v && v != 0)
                adjList[u-1].push_back(v-1);

        int m; cin >> m;
        while (m--) {
            int s; cin >> s; s--;
            vi dfs_num(n, 0);
            for (int v = 0; v < (int) adjList[s].size(); v++)
                if (dfs_num[adjList[s][v]] == 0)
                    dfs(adjList[s][v], adjList, dfs_num);

            int cnt = count(dfs_num.begin(), dfs_num.end(), 0);
            cout << cnt;
            int printed = 0;
            for (int i = 0; printed != cnt; i++)
                if (dfs_num[i] == 0) {
                    cout << ' ' << i + 1;
                    printed++;
                }
            cout << endl;
        }
    }

    return 0;
}