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

int main() {
    double x1, y1, x2, y2, x3, y3;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        double x4 = 0.5 * (x1 + x2);
        double y4 = 0.5 * (y1 + y2);

        double alpha = 0.5*(x1*x2 - (x1 + x2)*x3 + x3*x3 + y1*y2 - (y1 + y2)*y3 + y3*y3)/((x2 - x3)*y1 - (x1 - x3)*y2 + (x1 - x2)*y3);
        double c1 = x4 + alpha * (y2-y1);
        double c2 = y4 + alpha * (x1-x2);
        printf("%.2f\n", 2 * PI * hypot(y1 - c2, x1 - c1));
    }

    return 0;
}