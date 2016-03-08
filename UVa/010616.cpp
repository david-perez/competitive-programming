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
typedef pair<long, long> l_l;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<l_l> vl_l;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, long> mil;
typedef map<long, long> mll;

int N, M, D;
ll memo[200][20][11];
ll nums[200];

ll mod(ll a, ll b) {
    return (a % b + b) % b;
}

ll nsumdiv(int i, int sum, int rem) {
    if (rem == 0)
        return sum == 0 ? 1 : 0;
    if (i == N)
        return 0;
    if (memo[i][sum][rem] != -1)
        return memo[i][sum][rem];

    return memo[i][sum][rem] = nsumdiv(i+1, sum, rem) + nsumdiv(i+1, mod(sum + nums[i], D), rem-1);
}

int main() {
    int Q, t = 1;
    while (cin >> N >> Q && !(N == 0 && Q == 0)) {
        for (int i = 0; i < N; i++)
            cin >> nums[i];

        printf("SET %d:\n", t++);
        for (int q = 1; q <= Q; q++) {
            cin >> D >> M;
            memset(memo, -1, sizeof memo);
            printf("QUERY %d: %lld\n", q, nsumdiv(0, 0, M));
        }

    }

    return 0;
}