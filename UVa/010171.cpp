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

int adjMat1[26][26]; // the graph as Manzoor sees it
int adjMat2[26][26]; // the graph as Prof. Miguel sees it
int V = 26;

void floyd(int adjMat[26][26]) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) {
                if (i == j) adjMat1[i][i] = adjMat2[i][i] = 0;
                else adjMat1[i][j] = adjMat2[i][j] = INF;
            }

        while (N--) {
            char a, dir, x, y;
            int c;
            cin >> a >> dir >> x >> y >> c;

            int u = x - 'A', v = y - 'A';
            if (u == v) continue;
            if (a == 'Y') {
                adjMat1[u][v] = c;
                if (dir == 'B')
                    adjMat1[v][u] = c;
            } else { // a == 'M'
                adjMat2[u][v] = c;
                if (dir == 'B')
                    adjMat2[v][u] = c;
            }
        }

        floyd(adjMat1);
        floyd(adjMat2);

        char a, b;
        cin >> a >> b;
        int s = a - 'A';
        int d = b - 'A';

        set<int> sols;
        int m = INT_MAX;
        for (int k = 0; k < V; k++) {
            if (adjMat1[s][k] >= INF || adjMat2[d][k] >= INF)
                continue;
            if (adjMat1[s][k] + adjMat2[d][k] < m) {
                sols.clear();
                m = adjMat1[s][k] + adjMat2[d][k];
                sols.insert(k);
            } else if (adjMat1[s][k] + adjMat2[d][k] == m)
                sols.insert(k);
        }

        if (sols.size() == 0) cout << "You will never meet." << endl;
        else {
            cout << m;
            for (int x : sols)
                cout << ' ' << char('A' + x);
            cout << endl;
        }
    }

    return 0;
}