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

/**
 * Counts number of inversions in v[i...j].
 * O(n logn)
 */
ll invCount(int i, int j, vi &v) {
    if (i == j) return 0;

    int p = i + (j - i + 1) / 2; // pivot

    ll inv_count = invCount(i, p-1, v) + invCount(p, j, v);

    int k = i, l = p;
    vi w;
    while (k < p && l <= j) {
        if (v[l] < v[k]) { // inversion
            inv_count += (p - k);
            w.push_back(v[l]);
            l++;
        } else {
            w.push_back(v[k]);
            k++;
        }
    }

    while (k < p) {
        w.push_back(v[k]);
        k++;
    }

    while (l <= j) {
        w.push_back(v[l]);
        l++;
    }

    for (int m = 0; m < w.size(); m++)
        v[i + m] = w[m];

    return inv_count;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vi v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        cout << invCount(0, n-1, v) << endl;
    }

    return 0;
}