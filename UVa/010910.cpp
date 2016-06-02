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

int P;
int memo[71][71];

int F(int n, int t) {
    if (n == 0 && t == 0) return 1;
    if (n == 0) return 0;
    if (t < P) return 0;

    if (memo[n][t] != -1) return memo[n][t];

    int sum = 0;
    for (int p = P; p <= t; p++)
        sum += F(n - 1, t - p);

    return memo[n][t] = sum;
}

int main() {
    int K, N, T;
    cin >> K;
    while (K--) {
        cin >> N >> T >> P;
        memset(memo, -1, sizeof memo);
        cout << F(N, T) << endl;
    }

    return 0;
}