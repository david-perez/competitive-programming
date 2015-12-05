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

const int R = 9;
const int C = 9;

int m[R][C];
int mw[R][C];
int mb[R][C];
int maskw[R][C];
int maskb[R][C];

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int floodfill(int r, int c, int c1, int c2, int grid[R][C], int mask[R][C]) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (mask[r][c] == 1 || grid[r][c] == c2) return 0;
    int ans = 1;
    grid[r][c] = c1;
    mask[r][c] = 1;
    for (int d = 0; d < 4; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2, grid, mask);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char b;
        int white = 0, black = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> b;
                if (b == 'O') m[i][j] = 0, mw[i][j] = 0, mb[i][j] = 0, white++;
                else if (b == 'X') m[i][j] = 1, mw[i][j] = 1, mb[i][j] = 1, black++;
                else m[i][j] = -1, mw[i][j] = -1, mb[i][j] = -1;
            }
        }
        
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                maskw[i][j] = 0, maskb[i][j] = 0;
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (m[i][j] == 0) floodfill(i, j, 0, 1, mw, maskw);
                if (m[i][j] == 1) floodfill(i, j, 1, 0, mb, maskb);
            }
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (mw[i][j] == 0 && mb[i][j] == -1) white++;
                if (mb[i][j] == 1 && mw[i][j] == -1) black++;
            }
        }
        
        printf("Black %d White %d\n", black, white);
    }

    return 0;
}