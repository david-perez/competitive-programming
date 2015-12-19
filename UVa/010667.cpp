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

int main() {
    int grid[100][100];
    int p, s, n, r1, c1, r2, c2;
    cin >> p;
    while (p--) {
        cin >> s >> n;
        
        for (int i = 0; i < s; i++)
            for (int j = 0; j < s; j++)
                grid[i][j] = 1;
        
        for (int i = 0; i < n; i++) {
            cin >> r1 >> c1 >> r2 >> c2;
            for (int k = r1-1; k <= r2-1; k++)
                for (int l = c1-1; l <= c2-1; l++)
                    grid[k][l] = -100 * 100;
        }
        
        for (int i = 0; i < s; i++)
            for (int j = 0; j < s; j++) {
                if (i > 0) grid[i][j] += grid[i-1][j];
                if (j > 0) grid[i][j] += grid[i][j-1];
                if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
            }
        
        int maxSubRect = 0, subRect;
        for (int i0 = 0; i0 < s; i0++)
            for (int j0 = 0; j0 < s; j0++)
                for (int i1 = i0; i1 < s; i1++)
                    for (int j1 = j0; j1 < s; j1++) {
                        if (grid[i1][j1] == 0) break;
                        subRect = grid[i1][j1];
                        if (i0 > 0) subRect -= grid[i0-1][j1];
                        if (j0 > 0) subRect -= grid[i1][j0-1];
                        if (i0 > 0 && j0 > 0) subRect += grid[i0-1][j0-1];
                        maxSubRect = max(maxSubRect, subRect);
                    }
        
        cout << maxSubRect << endl;
    }
    
    return 0;
}