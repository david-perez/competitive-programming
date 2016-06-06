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

char g[10][10];
int d[10][10];

int main() {
    int m, n, x, y;
    while (cin >> m >> n >> y && !(m == 0 && n == 0 && y == 0)) {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
                d[i][j] = 0;
            }

        x = 0; y--;
        int loop = 0, cnt = 1;

        while (0 <= x && x < m && 0 <= y && y < n) {
            if (d[x][y] == 0) d[x][y] = cnt;
            else {
                loop = cnt - d[x][y];
                break;
            }

            if (g[x][y] == 'N') x--;
            else if (g[x][y] == 'E') y++;
            else if (g[x][y] == 'W') y--;
            else x++;

            cnt++;
        }

        if (loop != 0) printf("%d step(s) before a loop of %d step(s)\n", d[x][y] - 1, loop);
        else printf("%d step(s) to exit\n", cnt - 1);
    }

    return 0;
}