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

int C;
int adjMat[100][100];

void floyd() {
    for (int k = 0; k < C; k++)
        for (int i = 0; i < C; i++)
            for (int j = 0; j < C; j++)
                adjMat[i][j] = min(adjMat[i][j], max(adjMat[i][k], adjMat[k][j]));
}

int main() {
    int S, Q, t = 1;
    while (cin >> C >> S >> Q && !(C == 0 && S == 0 && Q == 0)) {
        if (t > 1) cout << endl;

        for (int i = 0; i < C; i++)
            for (int j = 0; j < C; j++) {
                if (i == j) adjMat[i][j] = 0;
                else adjMat[i][j] = INF;
            }

        while (S--) {
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            c1--, c2--;
            adjMat[c1][c2] = d;
            adjMat[c2][c1] = d;
        }

        floyd();

        printf("Case #%d\n", t++);

        while (Q--) {
            int c1, c2;
            cin >> c1 >> c2;
            c1--, c2--;
            if (adjMat[c1][c2] < INF)
                cout << adjMat[c1][c2] << endl;
            else
                cout << "no path" << endl;
        }
    }

    return 0;
}