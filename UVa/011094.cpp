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

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

char matrix[20][20];
int M, N;

int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= M) return 0;
    if (c < 0) c = N - 1;
    if (c >= N) c = 0;
    if (matrix[r][c] != c1) return 0;
    matrix[r][c] = c2;
    int ans = 1;
    for (int i = 0; i < 4; i++)
        ans += floodfill(r + dr[i], c + dc[i], c1, c2);
    return ans;
}

int main() {
    int r, c, ans;
    char land;
    while (scanf("%d %d", &M, &N) == 2) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> matrix[i][j];
        cin >> r >> c; cin.get();
        
        // first, set to water the continent of the king
        land = matrix[r][c];
        floodfill(r, c, land, '\0');
        
        // and now find the continent with maximum area
        ans = 0;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                ans = max(ans, floodfill(i, j, land, '\0'));
        cout << ans << endl;
        
        cin.get(); // blank line between input sets
    }
    return 0;
}