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

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int main() {
    char grid[100][100];
    int N, M, S;
    while (cin >> N >> M >> S && !(N == 0 && M == 0 && S == 0)) {
        int r, c, dir;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'N') r = i, c = j, dir = 0;
                else if (grid[i][j] == 'L') r = i, c = j, dir = 1;
                else if (grid[i][j] == 'S') r = i, c = j, dir = 2;
                else if (grid[i][j] == 'O') r = i, c = j, dir = 3;
            }

        int stickers = 0;
        while (S--) {
            char ins;
            cin >> ins;
            if (ins == 'F') {
                int nxtr = r + dr[dir], nxtc = c + dc[dir];
                if (nxtr < 0 || N <= nxtr || nxtc < 0 || M <= nxtc || grid[nxtr][nxtc] == '#') continue;
                r = nxtr, c = nxtc;
            } else if (ins == 'D') dir = (dir + 1) % 4;
            else {
                if (dir == 0) dir = 3;
                else dir--;
            }
            if (grid[r][c] == '*') stickers++, grid[r][c] = '.';
        }

        cout << stickers << endl;
    }

    return 0;
}