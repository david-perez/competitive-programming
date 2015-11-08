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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

vector<vi> adjList;
vi colors;

bool isBipartite(int s) {
    queue<int> q;
    q.push(s);
    colors[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < adjList[u].size(); j++) {
            int t = adjList[u][j];
            if (colors[t] == -1) {
                colors[t] = 1 - colors[u];
                q.push(t);
            } else if (colors[t] == colors[u]) return false;
        }
    }
    return true;
}

int main() {
    int n, l, u, v;
    while (cin >> n, n != 0) {
        colors.assign(n, -1);
        adjList.assign(n, vi());
        cin >> l;
        while (l--) {
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        cout << (isBipartite(0) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    }

    return 0;
}