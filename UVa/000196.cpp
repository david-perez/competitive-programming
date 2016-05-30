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

int m[999][18278];

int col_to_int(string col) {
    int b = 1;
    int v = 0;
    for (int i = col.length() - 1; i >= 0; i--) {
        v += (col[i] - 'A' + 1) * b;
        b *= 26;
    }

    return v - 1;
}

ii token_to_cell(string token) {
    int i = 0;
    while (isalpha(token[i])) i++;
    string col = token.substr(0, i);
    string row = token.substr(i);

    return ii(stoi(row) - 1, col_to_int(col));
}

void dfs(ii u, map<ii, vii> &adjList, map<ii, bool> &dfs_num) {
    dfs_num[u] = true;

    vii out = adjList[u];
    for (int v = 0; v < out.size(); v++)
        if (!dfs_num[out[v]])
            dfs(out[v], adjList, dfs_num);

    // this cell's dependencies have all been resolved
    for (int v = 0; v < out.size(); v++)
        m[u.first][u.second] += m[out[v].first][out[v].second];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int r, c; cin >> c >> r; cin.get();

        map<ii, vii> adjList; // maps cells which have formulae to their contents
        map<ii, bool> vis;

        for (int i = 0; i < r; i++) {
            string s; getline(cin, s);
            stringstream ss(s);
            for (int j = 0; j < c; j++) {
                string t; ss >> t;
                if (t[0] == '=') {
                    t.erase(0, 1);
                    stringstream st(t);
                    string token;
                    vii out;
                    while (getline(st, token, '+')) {
                        ii cell = token_to_cell(token);
                        out.push_back(cell);
                        vis[cell] = false;
                    }
                    adjList[ii(i, j)] = out;
                    vis[ii(i, j)] = false;
                    m[i][j] = 0;
                } else
                    m[i][j] = stoi(t);
            }
        }

        for (auto &p : adjList)
            if (!vis[p.first])
                dfs(p.first, adjList, vis);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c-1; j++)
                cout << m[i][j] << ' ';
            cout << m[i][c-1] << endl;
        }
    }

    return 0;
}