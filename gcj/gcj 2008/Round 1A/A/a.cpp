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

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.out", "w", stdout);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int n; cin >> n;
        vll v1, v2;
        for (int j = 0; j < n; j++) {
            ll r; cin >> r;
            v1.push_back(r);
        }
        for (int j = 0; j < n; j++) {
            ll r; cin >> r;
            v2.push_back(r);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<ll>());
        ll sp = 0;
        for (int i = 0; i < n; i++)
            sp += v1[i]*v2[i];
        printf("Case #%d: %lld\n", i, sp);
    }

    return 0;
}