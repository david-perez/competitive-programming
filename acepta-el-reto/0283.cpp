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

int F, C;
char grid[100][100];

int dr[] = {1,0,-1,0};
int dc[] = {0,-1,0,1};

int floodfill(int r, int c) {
    if (r < 0 || r >= F || c < 0 || c >= C) return 0;
    if (grid[r][c] != '#') return 0;
    int ans = 1;
    grid[r][c] = ' ';
    for (int d = 0; d < 4; d++)
        ans += floodfill(r + dr[d], c + dc[d]);

    return ans;
}

int main() {
    while (cin >> F >> C) {
        cin.get();
        for (int i = 0; i < F; i++) {
            string s; getline(cin, s);
            for (int j = 0; j < C; j++)
                grid[i][j] = s[j];
        }

        int ccMaxSize = 0;
        for (int i = 0; i < F; i++)
            for (int j = 0; j < C; j++)
                ccMaxSize = max(ccMaxSize, floodfill(i, j));

        cout << ccMaxSize << endl;
    }

    return 0;
}