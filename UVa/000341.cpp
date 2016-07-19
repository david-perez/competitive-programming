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

int NI;
int adjMat[10][10];
int pi[10][10];

void floyd() {
    for (int k = 0; k < NI; k++)
        for (int i = 0; i < NI; i++)
            for (int j = 0; j < NI; j++)
                if (adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                    pi[i][j] = pi[k][j];
                }
}

void printPath(int i, int j) {
    if (i != j) printPath(i, pi[i][j]);
    cout << ' ' << j+1;
}

int main() {
    int t = 1;
    while (cin >> NI && NI != 0) {
        for (int i = 0; i < NI; i++)
            for (int j = 0; j < NI; j++) {
                adjMat[i][j] = INF;
                pi[i][j] = i;
            }

        for (int u = 1; u <= NI; u++) {
            int n;
            cin >> n;
            while (n--) {
                int v, w;
                cin >> v >> w;
                adjMat[u-1][v-1] = w;
            }
        }

        for (int i = 0; i < NI; i++)
            adjMat[i][i] = 0;

        floyd();

        int s, d;
        cin >> s >> d;
        s--, d--;

        printf("Case %d: Path =", t++);
        printPath(s, d);
        printf("; %d second delay\n", adjMat[s][d]);
    }

    return 0;
}