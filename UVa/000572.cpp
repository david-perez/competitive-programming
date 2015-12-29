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
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

char grid[100][100];

int m, n;

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

/**
 * Floodfills the connected component of vertex value c1 at grid[r][c] with the value c2.
 * @param r
 * @param c
 * @param c1
 * @param c2
 * @return the size of the connected component.
 */
int floodfill(int r, int c, int c1, int c2) {
    if (r < 0 || r >= m || c < 0 || c >= n) return 0;
    if (grid[r][c] != c1) return 0;
    int ans = 1;
    grid[r][c] = c2;
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}

int main() {
    cin >> m >> n;
    while (m != 0) {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        
        int deposits = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (floodfill(i, j, '@', '*') > 0) deposits++;
        
        cout << deposits << endl;
        cin >> m >> n;
    }
    
    return 0;
}