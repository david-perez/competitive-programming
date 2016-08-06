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

char grid[60][60];

// N, E, S, W
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
char orient[] = {'N', 'E', 'S', 'W'};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> R >> C; cin.get();
        string s;
        for (int i = 0; i < R; i++) {
            getline(cin, s);
            for (int j = 0; j < C; j++)
                grid[i][j] = s[j];
        }

        int r, c, d = 0;
        cin >> r >> c;
        r--, c--;

        char b;
        while (cin >> b && b != 'Q') {
            if (b == 'R')
                d = (d + 1) % 4;
            else if (b == 'L') {
                if (d == 0) d = 3;
                else d--;
            } else if (b == 'F') {
                int rp = r + dr[d];
                int cp = c + dc[d];
                if (rp >= 0 && rp < R && cp >= 0 && cp < C && grid[rp][cp] == ' ')
                    r = rp, c = cp;
            }
        }

        printf("%d %d %c\n", r+1, c+1, orient[d]);
        if (T > 0) cout << endl;
    }

    return 0;
}