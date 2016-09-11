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

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point center(point p1, point p2, point p3) {
    double c1n = 0.5*((p1.y - p3.y)*p2.y*p2.y + p1.x*p1.x*p3.y - p2.x*p2.x*p3.y + p1.y*p1.y*p3.y + (p2.x*p2.x - p3.x*p3.x - p3.y*p3.y)*p1.y - (p1.x*p1.x - p3.x*p3.x + p1.y*p1.y - p3.y*p3.y)*p2.y);
    double c1d = (p2.x - p3.x)*p1.y - (p1.x - p3.x)*p2.y + p1.x*p3.y - p2.x*p3.y;

    double c2n = -0.5*((p1.x - p3.x)*p2.x*p2.x + p1.x*p1.x*p3.x - (p2.x - p3.x)*p1.y*p1.y + (p1.x - p3.x)*p2.y*p2.y - (p3.x*p3.x + p3.y*p3.y)*p1.x - (p1.x*p1.x - p3.x*p3.x - p3.y*p3.y)*p2.x);
    double c2d = (p2.x - p3.x)*p1.y - (p1.x - p3.x)*p2.y + p1.x*p3.y - p2.x*p3.y;

    return point(c1n / c1d, c2n / c2d);
}

int main() {
    double ax, ay, bx, by, cx, cy;
    while (cin >> ax >> ay >> bx >> by >> cx >> cy) {
        point p1(ax, ay), p2(bx, by), p3(cx, cy);
        point p = center(p1, p2, p3);

        double r = dist(p, p1);
        double c = -2*p.x;
        double d = -2*p.y;
        double e = p.y*p.y + p.x*p.x - r*r;

        printf("(x %s %.3f)^2 + (y %s %.3f)^2 = %.3f^2\n", p.x < 0 ? "+" : "-", abs(p.x), p.y < 0 ? "+" : "-", abs(p.y), r);
        printf("x^2 + y^2 %s %.3fx %s %.3fy %s %.3f = 0\n", c < 0 ? "-" : "+", abs(c), d < 0 ? "-" : "+", abs(d), e < 0 ? "-" : "+", abs(e));
        cout << endl;
    }

    return 0;
}