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

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int main() {
    char grid[100][100];
    int t, n, m, count;
    cin >> n >> m;
    t = 1;
    bool space = false;
    while (n != 0 && m != 0) {
        if (space) cout << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') continue;
                count = 0;
                for (int k = 0; k < 8; k++) {
                    if (0 <= i+dr[k] && n > i+dr[k] && 0 <= j+dc[k] && m > j+dc[k])
                        if (grid[i+dr[k]][j+dc[k]] == '*') count++;
                }
                grid[i][j] = count + '0';
            }
        }
        
        printf("Field #%d:\n", t);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << grid[i][j];
            cout << endl;
        }
        
        space = true;
        t++;
        cin >> n >> m;
    }
    
    return 0;
}