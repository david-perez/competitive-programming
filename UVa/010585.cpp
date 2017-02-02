#include <iostream>
#include <set>
#include <cmath>

using namespace std;

#define EPS 1e-9

struct point {
    double x, y;

    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
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

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        set<point> v;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            v.insert(point(x, y));
        }

        double sumX = 0, sumY = 0;
        for (point const &p: v) {
            sumX += p.x;
            sumY += p.y;
        }
        point s = point(sumX / n, sumY / n); // https://en.wikipedia.org/wiki/Centroid

        bool b = true;
        for (point const &p : v) {
            point q = translate(s, toVec(p, s));
            if (v.count(q) == 0) {
                b = false;
                break;
            }
        }

        cout << (b ? "yes" : "no") << endl;
    }

    return 0;
}