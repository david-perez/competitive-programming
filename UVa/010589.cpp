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

struct point {
    double x, y;

    point() : x(0), y(0) { }
    point(double _x, double _y) : x(_x), y(_y) { }
};

double distSq(point p1, point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

bool insideCircle(point p, point c, double r) {
    double eucSq = distSq(p, c);
    double rSq = r*r;
    return eucSq <= rSq;
}

int main() {
    int N;
    double a;
    while (cin >> N >> a && N != 0) {
        int M = 0;
        for (int i = 0; i < N; i++) {
            double x, y;
            cin >> x >> y;
            point p(x, y);
            if (insideCircle(p, point(0, 0), a) &&
                insideCircle(p, point(a, 0), a) &&
                insideCircle(p, point(a, a), a) &&
                insideCircle(p, point(0, a), a))
                    M++;
        }

        printf("%.5f\n", (double)M*a*a/N);
    }

    return 0;
}