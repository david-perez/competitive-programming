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

int memo[27][352][27];

int h(int L, int S, int c) {
    if (L == 0 && S == 0) return 1;
    if (L == 0 || S == 0 || c > S) return 0;

    if (memo[L][S][c] != -1) return memo[L][S][c];

    int colls = 0;
    for (int i = c+1; i <= 26; i++)
        colls += h(L-1, S-i, i);

    return memo[L][S][c] = colls;
}

int main() {
    memset(memo, -1, sizeof memo);
    int L, S, t = 1;
    while (cin >> L >> S && !(L == 0 && S == 0))
        printf("Case %d: %d\n", t++, ((L > 26 || S > 351) ? 0 : h(L, S, 0)));

    return 0;
}