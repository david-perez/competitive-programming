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
    set<ull> sheldon;
    for (int n = 1; n <= 64; n++)
        for (int m = 0; n + m <= 64; m++) { // given n, m generate all sheldon numbers <= 2^63
            ull x = ((1ULL << n) - 1); sheldon.insert(x);
            for (int i = 0; i <= (64 - n) / (n + m); i++) {
                x = (x << m);
                sheldon.insert(x);
                x = (x << n) | ((1ULL << n) - 1);
                sheldon.insert(x);
            }
        }
    sheldon.erase(0);

    ull x, y;
    while (cin >> x >> y) {
        auto it1 = sheldon.lower_bound(x), it2 = sheldon.upper_bound(y);
        cout << distance(it1, it2) << endl;
    }

    return 0;
}