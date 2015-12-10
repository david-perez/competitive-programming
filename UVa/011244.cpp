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
    int r, c, stars;
    bool isStar;
    cin >> r >> c;
    while (r != 0 && c != 0) {
        stars = 0;
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> grid[i][j];
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '*') {
                    isStar = true;
                    for (int k = 0; k < 8; k++) {
                        if (i+dr[k] < 0 || i+dr[k] >= r || j+dc[k] < 0 || j+dc[k] >= c) continue;
                        isStar &= (grid[i+dr[k]][j+dc[k]] == '.');
                    }
                    if (isStar) stars++;
                }
            }
        }
        
        cout << stars << endl;
        cin >> r >> c;
    }
    
    return 0;
}