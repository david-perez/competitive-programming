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

int n;
vvi adjList;
vi d;
vi pi;

int bfs(int s, ii rmEdge = ii(-1, -1), ii addEdge = ii(-1, -1)) {
    d.assign(n, INT_MAX);
    pi.assign(n, -1);
    d[s] = 0;
    pi[s] = -1;
    int ret = s;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        if (addEdge != ii(-1, -1))
            if (u == addEdge.first)
                adjList[u].push_back(addEdge.second);
            else if (u == addEdge.second)
                adjList[u].push_back(addEdge.first);

        for (int j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];

            if (rmEdge != ii(-1, -1) && ((u == rmEdge.first && v == rmEdge.second) || (u == rmEdge.second && v == rmEdge.first)))
                continue; // ignore this edge

            if (d[v] == INT_MAX) {
                d[v] = d[u] + 1;
                pi[v] = u;
                ret = v;
                q.push(v);
            }
        }

        if (addEdge != ii(-1, -1) && (u == addEdge.first || u == addEdge.second))
            adjList[u].pop_back();
    }

    return ret;
}

/**
 * Return the longest path in the connected component of the graph adjList that contains vertex s,
 * removing bidirectional edge rmEdge and adding bidirectional edge addEdge.
 */
vi longestPath(int s, ii rmEdge = ii(-1, -1), ii addEdge = ii(-1, -1)) {
    int u = bfs(s, rmEdge, addEdge);
    int v = bfs(u, rmEdge, addEdge);
    vi path;
    path.push_back(v);
    while (pi[v] != -1) {
        path.push_back(pi[v]);
        v = pi[v];
    }

    return path;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        cin >> n;
        adjList.assign(n, vi());

        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        vi v = longestPath(0); // a tree is connected so we can choose an arbitrary source vertex
        int diam = v.size() - 1;
        ii add = ii(-1, -1);
        ii rm = ii(-1, -1);
        for (int i = 0; i < v.size()-1; i++) {
            // remove edge (v[i], v[i+1]), thereby splitting the tree into two subtrees
            ii rmEdge = ii(v[i], v[i+1]);
            vi lp1 = longestPath(v[i], rmEdge);
            vi lp2 = longestPath(v[i+1], rmEdge);

            // join the centers of both longest paths in the subtrees
            ii addEdge = ii(lp1[lp1.size() / 2], lp2[lp2.size() / 2]);
            vi lp = longestPath(0, rmEdge, addEdge);
            if (lp.size() - 1 < diam) {
                diam = lp.size() - 1;
                add = addEdge;
                rm = rmEdge;
            }
        }

        cout << diam << endl;
        printf("%d %d\n", rm.first + 1, rm.second + 1);
        printf("%d %d\n", add.first + 1, add.second + 1);
    }

    return 0;
}