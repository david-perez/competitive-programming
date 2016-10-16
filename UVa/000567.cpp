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

int V = 20;
int adjMat[20][20];

void floyd() {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main() {
    int k;
    for (int t = 1; cin >> k; t++) {
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) {
                if (i == j) adjMat[i][j] = 0;
                else adjMat[i][j] = INF;
            }

        for (int u = 0; u < V-1; u++) {
            if (u != 0) cin >> k;
            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;
                v--;
                adjMat[u][v] = 1;
                adjMat[v][u] = 1;
            }
        }

        floyd();

        printf("Test Set #%d\n", t);

        int N;
        cin >> N;
        while (N--) {
            int A, B;
            cin >> A >> B;
            printf("%2d to %2d: %d\n", A, B, adjMat[A-1][B-1]);
        }

        cout << endl;
    }

    return 0;
}