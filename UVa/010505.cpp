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
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int bfs(const vector<vi> &adjList, int u, vi &colors) {
    int c[2]; c[0] = 1; c[1] = 0;
    colors[u] = 0;
    queue<int> q;
    q.push(u);
    bool bipartite = true;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];
            if (colors[v] == -1) {
                colors[v] = 1 - colors[u];
                c[colors[v]]++;
                q.push(v);
            } else if (colors[v] == colors[u]) { // this connected component is not bipartite
                bipartite = false;
            }
        }
    }
    return bipartite ? max(c[0], c[1]) : 0;
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int N, p, v;
        cin >> N;
        vector<vi> adjList; adjList.assign(N, vi());
        for (int u = 0; u < N; u++) {
            cin >> p;
            while (p--) {
                cin >> v;
                adjList[u].push_back(v-1);
                adjList[v-1].push_back(u);
            }
        }
        
        // we assume the graph we read is bipartite
        
        int guests = 0;
        vi colors; colors.assign(N, -1);
        for (int u = 0; u < N; u++)
            if (colors[u] == -1) guests += bfs(adjList, u, colors);
        
        cout << guests << endl;
    }
    
    return 0;
}