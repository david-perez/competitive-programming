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

bool kahn(vvi &adjList, vi &topo) {
    vi inDeg(adjList.size(), 0);

    for (int u = 0; u < adjList.size(); u++)
        for (int v = 0; v < adjList[u].size(); v++)
            inDeg[adjList[u][v]]++;

    queue<int> q;
    for (int u = 0; u < inDeg.size(); u++)
        if (inDeg[u] == 0) q.push(u);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v = 0; v < adjList[u].size(); v++)
            if (--inDeg[adjList[u][v]] == 0) q.push(adjList[u][v]);
    }

    for (int u = 0; u < inDeg.size(); u++)
        if (inDeg[u] != 0) return true;
    return false;
}

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        vvi adjList(n, vi());
        while (m--) {
            int u, v;
            cin >> u >> v; u--; v--;
            adjList[u].push_back(v);
        }

        vi topo;
        kahn(adjList, topo);
        for (int i = 0; i < topo.size()-1; i++)
            printf("%d ", topo[i]+1);
        cout << topo[topo.size()-1]+1 << endl;
    }

    return 0;
}