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

int row[8];

bool place(int r, int c) {
    for (int prev = 0; prev < c; prev++)
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) return false;
    return true;
}

int min_moves(int c) {
    if (c == 8) return 0;
    int m = 7;
    int t = row[c];
    for (int r = 0; r < 8; r++)
        if (place(r, c)) {
            row[c] = r;
            m = min(m, min_moves(c+1) + (r == t ? 0 : 1));
            row[c] = t;
        }
    return m;
}

int main() {
    int T = 1;
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        for (int i = 0; i < 8; i++) {
            ss >> row[i];
            row[i]--;
        }
        printf("Case %d: %d\n", T++, min_moves(0));
    }

    return 0;
}