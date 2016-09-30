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

int n;
int sum;
int candy[32];
int memo[32][641][641];

int f(int i, int a, int b) {
    if (i == n) { // all candies are distributed
        int c = sum - a - b;
        return max(a, max(b, c)) - min(a, min(b, c));
    }

    if (memo[i][a][b] != -1) return memo[i][a][b];

    return memo[i][a][b] = min(f(i+1, a+candy[i], b), min(f(i+1, a, b+candy[i]), f(i+1, a, b)));
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> candy[i];
            sum += candy[i];
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= sum; j++)
                for (int k = 0; k <= sum; k++)
                    memo[i][j][k] = -1;

        printf("Case %d: %d\n", t, f(0, 0, 0));
    }

    return 0;
}