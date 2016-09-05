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

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) { }
};

vec toVec(point a, point b) {
    return vec(b.x-a.x, b.y-a.y);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

vec rotate(vec v, double theta) {
    double rad = PI / 180 * theta;

    return vec(v.x * cos(rad) - v.y * sin(rad),
               v.x * sin(rad) + v.y * cos(rad));
}

point center(point p1, point p2, point p3) {
    double c1n = 0.5*((p1.y - p3.y)*p2.y*p2.y + p1.x*p1.x*p3.y - p2.x*p2.x*p3.y + p1.y*p1.y*p3.y + (p2.x*p2.x - p3.x*p3.x - p3.y*p3.y)*p1.y - (p1.x*p1.x - p3.x*p3.x + p1.y*p1.y - p3.y*p3.y)*p2.y);
    double c1d = (p2.x - p3.x)*p1.y - (p1.x - p3.x)*p2.y + p1.x*p3.y - p2.x*p3.y;

    double c2n = -0.5*((p1.x - p3.x)*p2.x*p2.x + p1.x*p1.x*p3.x - (p2.x - p3.x)*p1.y*p1.y + (p1.x - p3.x)*p2.y*p2.y - (p3.x*p3.x + p3.y*p3.y)*p1.x - (p1.x*p1.x - p3.x*p3.x - p3.y*p3.y)*p2.x);
    double c2d = (p2.x - p3.x)*p1.y - (p1.x - p3.x)*p2.y + p1.x*p3.y - p2.x*p3.y;

    return point(c1n / c1d, c2n / c2d);
}

int main() {
    int N;
    for (int t = 1; cin >> N && N != 0; t++) {
        vector<point> v;
        for (int i = 0; i < 3; i++) {
            double x, y;
            cin >> x >> y;
            v.push_back(point(x, y));
        }

        point c = center(v[0], v[1], v[2]);

        double minx = v[0].x, maxx = v[0].x, miny = v[0].y, maxy = v[0].y;
        vec u = toVec(c, v[0]);
        double theta = 360.0 / N;
        for (int i = 0; i < N - 1; i++) {
            u = rotate(u, theta);
            point q = translate(c, u);
            minx = min(minx, q.x);
            maxx = max(maxx, q.x);
            miny = min(miny, q.y);
            maxy = max(maxy, q.y);
        }

        printf("Polygon %d: %.3f\n", t, (maxx - minx)*(maxy - miny));

    }

    return 0;
}