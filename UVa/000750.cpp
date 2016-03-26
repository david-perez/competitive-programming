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

int soln = 1, a, b;
int row[8];

bool place(int r, int c) {
    for (int prev = 0; prev < c; prev++)
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) return false;
    return true;
}

void backtrack(int c) {
    if (c == 8 && row[b] == a) {
        printf("%2d      ", soln++);
        for (int i = 0; i < 7; i++)
            printf("%d ", row[i]+1);
        cout << row[7]+1 << endl;
        return;
    }
    for (int r = 0; r < 8; r++) {
        if (place(r, c)) {
            row[c] = r;
            backtrack(c + 1);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        soln = 1;
        cin >> a >> b; a--, b--;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        memset(row, 0, sizeof row);
        backtrack(0);
        if (T) cout << endl;
    }

    return 0;
}