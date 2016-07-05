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

double dis(double u, double t, double a) {
    return u*t + 0.5*a*t*t;
}

double tim(double v, double u, double a) {
    return (v-u) / a;
}

int main() {
    int c = 1;
    int n;
    while (cin >> n && n != 0) {
        double x, y, z;
        cin >> x >> y >> z;
        if (n == 1) {
            double a = (y-x)/z;
            printf("Case %d: %.3f %.3f\n", c++, dis(x, z, a), a);
        } else if (n == 2) {
            double t = tim(y, x, z);
            printf("Case %d: %.3f %.3f\n", c++, dis(x, t, z), tim(y, x, z));
        } else if (n == 3) {
            double v = sqrt(2*y*z + x*x);
            printf("Case %d: %.3f %.3f\n", c++, v, tim(v, x, y));
        } else { // n == 4
            double u = sqrt(x*x - 2*y*z);
            printf("Case %d: %.3f %.3f\n", c++, u, tim(x, u, y));
        }
    }

    return 0;
}