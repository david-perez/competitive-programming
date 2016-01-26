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
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<long> vl;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

/**
 * Extended euclid's algorithm.
 * ax + by = d = gcd(a, b).
 * @param a
 * @param b
 * @param x
 * @param y
 * @return d
 */
ll eea(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0, yy = x = 1;
    while (b) {
        ll q = a/b, t = b; b = a%b; a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t;
    }
    return a;
}

int main() {
    ll a, x, y;
    
    while (cin >> a && a != 0) {
        ll sum = a;
        ll gcd = a;
        while (cin >> a && a != 0) {
            sum += a;
            gcd = eea(gcd, a, x, y);
        }

        cout << sum / gcd << endl;
    }
    
    return 0;
}