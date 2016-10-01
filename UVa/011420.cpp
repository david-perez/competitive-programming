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
#define PI acos(-1)
#define EPS 1e-9

ll memo[66][66][2];

ll f(int n, int s, int x) {
    if (s > n) return 0;
    if (n == 1) { // most bottom drawer
        if (s == 1)
            if (x == 1) return 1;
            else return 0;
        else if (s == 0)
            if (x == 1) return 1;
            else return 2;
        else return 0;
    }

    if (memo[n][s][x] != -1) return memo[n][s][x];

    if (x == 1) return memo[n][s][x] = f(n-1, s-1, 1) + f(n-1, s, 0);
    else return memo[n][s][x] = f(n-1, s, 1) + f(n-1, s, 0);
}

int main() {
    memset(memo, -1, sizeof memo);
    int n, s;
    while (cin >> n >> s && !(n < 0 && s < 0))
        cout << f(n, s, 1) << endl;

    return 0;
}