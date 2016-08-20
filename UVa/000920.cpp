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

    bool operator ==(const point &o) const {
        return fabs(x - o.x) < EPS && fabs(y - o.y) < EPS;
    }

    bool operator <(const point &o) const {
        if (fabs(x - o.x) > EPS) return x < o.x;
        return y < o.y;
    }
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        vector<point> v;
        int N;
        cin >> N;
        while (N--) {
            double x, y;
            cin >> x >> y;
            v.push_back(point(x, y));
        }
        sort(v.begin(), v.end());

        double d = 0;
        point p = v[v.size() - 1];
        for (int i = v.size() - 2; i >= 0; i--) {
            while (i >= 0 && v[i].y <= p.y)
                i--;

            if (i >= 0) {
                point q = v[i];
                point r = v[i+1];
                double a = (p.y*(r.x - q.x) - r.x*q.y + r.y*q.x) / (r.y - q.y);
                d += dist(q, point(a, p.y));
                p = q;
            }
        }

        printf("%.2f\n", d);
    }

    return 0;
}