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

double horner(vi &pol, double x) {
    double ev = pol[0];
    for (int n = 1; n < pol.size(); n++)
        ev = ev * x + pol[n];
    return ev;
}

int main() {
    int d;
    while (cin >> d && d != 20) {
        vi pol;
        while (d-- >= 0) {
            int a; cin >> a;
            pol.push_back(a);
        }
        int n; cin >> n;
        double h = 1.0 / n, xi = 0, area = 0;
        while (n--) {
            double fxi = horner(pol, xi);
            fxi = min(fxi, 1.0);
            fxi = max(fxi, 0.0);
            area += fxi;
            xi += h;
        }
        area *= h;

        if (abs(0.5 - area) <= 0.001) cout << "JUSTO" << endl;
        else if (area < 0.5) cout << "ABEL" << endl;
        else cout << "CAIN" << endl;
    }

    return 0;
}