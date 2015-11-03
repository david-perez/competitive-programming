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

vector<vi> AdjList;
int n, c;

vi topoSort() {
    c = 0;
    vi inDeg(n+1, 0);
    vi sorted;
    queue<int> q;
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < AdjList[i].size(); j++)
            inDeg[AdjList[i][j]]++;
    
    for (int i = 1; i <= n; i++)
        if (inDeg[i] == 0) q.push(i), c++;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        sorted.push_back(u);
        for (int i = 0; i < AdjList[u].size(); i++) {
            int v = AdjList[u][i];
            if (--inDeg[v] == 0)
                q.push(v), c++;
        }
    }
    
    return sorted;
}

int main() {
    int m, u, v;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        AdjList.assign(n+1, vi());
        while (m--) {
            cin >> u >> v;
            AdjList[u].push_back(v);
        }
        
        vi sorted = topoSort();
        if (c != n) cout << "IMPOSSIBLE" << endl;
        else
            for (int i = 0; i < n; i++)
                cout << sorted[i] << endl;
        
        cin >> n >> m;
    }

    return 0;
}
