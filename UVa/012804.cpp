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
#include <numeric>

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

const int UNVISITED = 0, EXPLORED = 1, VISITED = 2;

bool graphCheck(int u, vvi &adjList, vi &dfs_num, vi &dfs_parent) {
    bool cycle = false;
    dfs_num[u] = EXPLORED;
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            cycle = graphCheck(v, adjList, dfs_num, dfs_parent) || cycle; // the order of the || arguments is important because of lazy evaluation
        } else if (dfs_num[v] == EXPLORED)
            cycle = true;
        else if (dfs_num[v] == VISITED) {
            // Cross edge
        }
    }
    dfs_num[u] = VISITED;

    return cycle;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int L;
        cin >> L; cin.get();
        vvi dark(L+1, vi());

        for (int u = 0; u < L; u++) {
            string s;
            getline(cin, s);

            if (s[0] == 'A')
                dark[u].push_back(u+1);
            else {
                stringstream ss(s);
                char c;
                int  l;
                ss >> c >> l;
                l--;

                if (c == 'J')
                    dark[u].push_back(l);
                else if (c == 'C') {
                    dark[u].push_back(l);
                    dark[u].push_back(u+1);
                }
            }
        }

        vi dfs_num_dark(L+1, 0);
        vi dfs_parent_dark(L+1, 0);
        bool cycle_dark = graphCheck(0, dark, dfs_num_dark, dfs_parent_dark);

        if (!cycle_dark && dfs_num_dark[L] == VISITED) cout << "ALWAYS" << endl;
        else if (cycle_dark && dfs_num_dark[L] == UNVISITED) cout << "NEVER" << endl;
        else cout << "SOMETIMES" << endl;
    }

    return 0;
}