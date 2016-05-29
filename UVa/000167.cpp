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

int m[8][8];
int row[8];
int sum;

bool place(int r, int c) {
    for (int prev = 0; prev < c; prev++)
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) return false;
    return true;
}

void backtrack(int c) {
    if (c == 8) {
        int sump = 0;
        for (int j = 0; j < 8; j++)
            sump += m[row[j]][j];
        sum = max(sum, sump);
    }

    for (int r = 0; r < 8; r++)
        if (place(r, c)) {
            row[c] = r;
            backtrack(c + 1);
        }
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> m[i][j];

        memset(row, 0, sizeof row);
        sum = 0;
        cout.width(5);
        backtrack(0);
        cout << right << sum << endl;
    }

    return 0;
}