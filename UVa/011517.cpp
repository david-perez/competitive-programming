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

int dp[30001];

int main() {
    int T;
    cin >> T;
    while (T--) {
        fill_n(dp, 30000, INT_MAX);
        dp[0] = 0;
        int p, n; cin >> p >> n;
        while (n--) {
            int c; cin >> c;
            for (int i = 30001 - c - 1; i >= 0; i--)
                if (dp[i] < INT_MAX) dp[i+c] = min(dp[i+c], dp[i]+1);
        }
        while (true) {
            if (dp[p] != INT_MAX) {
                printf("%d %d\n", p, dp[p]);
                break;
            }
            p++;
        }
    }

    return 0;
}