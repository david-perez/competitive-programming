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

bool satisfies(vi &perm, vector<pair<ii, int>> &constraints) {
    for (int i = 0; i < constraints.size(); i++) {
        int a = constraints[i].first.first, b = constraints[i].first.second, c = constraints[i].second;
        auto ai = find(perm.begin(), perm.end(), a);
        auto bi = find(perm.begin(), perm.end(), b);
        int d = ai < bi ? distance(ai, bi) : distance(bi, ai);
        if (c > 0 && d > c) return false;
        if (c < 0 && d < -c) return false;
    }
    return true;
}

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        vector<pair<ii, int>> constraints;
        while (m--) {
            int a, b, c; cin >> a >> b >> c;
            constraints.push_back(pair<ii, int>(ii(a, b), c));
        }
        vi perms;
        for (int i = 0; i < n; i++) perms.push_back(i);
        int cnt = 0;
        do
            if (satisfies(perms, constraints)) cnt++;
        while (next_permutation(perms.begin(), perms.end()));
        cout << cnt << endl;
    }

    return 0;
}