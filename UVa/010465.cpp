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

int main() {
    int n, m, t;
    while (cin >> n >> m >> t) {
        vi dp(t+1, -1);
        dp[0] = 0;

        for (int i = min(n, m); i <= t; i++) {
            if (i >= n && dp[i-n] != -1) dp[i] = dp[i-n] + 1;
            if (i >= m && dp[i-m] != -1) dp[i] = max(dp[i], dp[i-m] + 1);
        }

        int i = t;
        while (dp[i] == -1) i--;
        cout << dp[i];
        if (i != t) cout << ' ' << t - i;
        cout << endl;
    }

    return 0;
}