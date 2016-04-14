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

int digits(int i) { // i > 0
    int cnt = 0;
    while (i > 0) {
        cnt++;
        i /= 10;
    }
    return cnt;
}

int ndigits(int n) { // number of digits of the numbers [1...n]
    if (n < 1) return 0;
    int d = digits(n);
    if (d == 1) return n;
    int p = 10, s = 1;
    for (int i = 1; i <= d-2; i++) {
        s += p * (i+1);
        p *= 10;
    }
    return 9*s + d * (n-p+1);
}

int a(int x, int y) { // number of digits of the numbers [x...y], 1 <= x <= y
    return ndigits(y) - ndigits(x-1);
}

int main() {
    int p1, p2;
    while (cin >> p1 >> p2 && !(p1 == 0 && p2 == 0)) {
        int i = p1, j = p2, mid = a(p1, p2) / 2, m;
        while (i <= j) {
            m = (i + j) / 2;
            int d1 = a(p1, m);
            if (d1 == mid) break;
            if (d1 < mid) i = m + 1;
            else j = m - 1;
        }
        if (a(p1, m) > a(m+1, p2)) m--;
        cout << m << endl;
    }

    return 0;
}