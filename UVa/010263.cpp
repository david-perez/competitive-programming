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
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

struct point {
    double x, y;
    
    point() : x(0), y(0) { }
    point(double _x, double _y) : x(_x), y(_y) { }
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) { }
};

vec toVec(point a, point b) {
   return vec(b.x-a.x, b.y-a.y); 
}

vec scale(vec v, double s) {
    return vec(v.x*s, v.y*s);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
    return a.x*b.x + a.y*b.y;
}

double norm_sq(vec v) {
    return v.x*v.x  + v.y*v.y;
}

/**
 * Returns the distance from p to the line defined by two distinct points a and b.
 * The closest point to p on the line is stored in c.
 * O(1)
 * @param p
 * @param a
 * @param b
 * @param c
 * @return 
 */
double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

/**
 * Returns the distance from p to the segment defined by two points a and b.
 * The closest point to p on the segment is stored in c.
 * O(1)
 * @param p
 * @param a
 * @param b
 * @param c
 * @return 
 */
double distToSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);
        return dist(p, a);
    } else if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    } else return distToLine(p, a, b, c);
}

int main() {
    double xm, ym, a, b, c, d;
    int N;
    while (scanf("%lf %lf", &xm, &ym) == 2) {
        vector<pair<point, point> > railway;
        cin >> N;
        cin >> a >> b;
        while (N--) {
            cin >> c >> d;
            railway.push_back(pair<point, point>(point(a, b), point(c, d)));
            a = c, b = d;
        }
        
        point m(xm, ym), q;
        double minDist = distToSegment(m, railway[0].first, railway[0].second, q);
        point p = q;
        for (int i = 0; i < railway.size(); i++) {
            double dist = distToSegment(m, railway[i].first, railway[i].second, q);
            if (dist < minDist) minDist = dist, p = q;
        }
        
        printf("%.4f\n%.4f\n", p.x, p.y);
    }
    
    return 0;
}