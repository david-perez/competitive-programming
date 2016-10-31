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
#include <numeric>

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
#define PI acos(-1)
#define EPS 1e-9

int memo[500][500];

int giant(int n, int k) {
    if (n <= 1) return 0;
    if (memo[n][k] != -1) return memo[n][k];

    int minn = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int a = giant(i-1, k); // giant((k+i-1)-(k+1)+1, k)
        int b = giant(n-i, k+i); // giant((k+n)-(k+i+1)+1, k+i)
        minn = min(minn, n*(k+i) + a + b);
    }

    return memo[n][k] = minn;
}

int main() {
    memset(memo, -1, sizeof memo);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k;
        cin >> n >> k;
        printf("Case %d: %d\n", t, giant(n, k));
    }

    return 0;
}