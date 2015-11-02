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

#define INF (INT_MAX>>1)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

vector<vi> AdjList;
vi d;
int p;

void bfs(int s) {
    d.assign(p, INF); d[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < AdjList[u].size(); j++) {
            int v = AdjList[u][j];
            if (d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int u, v, edges;
        cin >> p >> edges;
        AdjList.assign(p, vi());
        while (edges--) {
            cin >> u >> v;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        
        bfs(0);
        for (int i = 1; i < p; i++) 
            cout << d[i] << endl;
        if (t) cout << endl;
    }

    return 0;
}