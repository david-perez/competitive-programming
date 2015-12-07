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
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int grid[99][99];
int R, C;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

/**
 * Floodfills the connected component of vertex value c1 at grid[r][c].
 * @param r
 * @param c
 * @param c1
 * @param c2
 * @return the size of the connected component.
 */
int floodfill(int r, int c, int c1, int c2) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (grid[r][c] != c1) return 0;
    int ans = 1;
    grid[r][c] = c2;
    for (int d = 0; d < 4; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}

int main() {
    int M, i0, j0;
    cin >> M;
    string b;
    while (M--) {
        cin >> i0 >> j0; cin.get();
        
        R = 0;
        getline(cin, b);
        C = b.size();
        while (b != "") {
            for (int j = 0; j < b.size(); j++)
                grid[R][j] = b[j] == '0' ? 0 : 1;
            
            getline(cin, b);
            R++;
        }
        
        cout << floodfill(i0-1, j0-1, 0, -1) << endl;
        if (M) cout << endl;
    }
    
    return 0;
}
