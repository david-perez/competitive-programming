#include <iostream>
#include <set>
#include <cmath>

using namespace std;

#define EPS 1e-9

struct point {
    double x, y;

    point() {
        x = y = 0.0;
    }

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
    double d[8];
    while (cin >> d[0] >> d[1] >> d[2] >> d[3] >> d[4] >> d[5] >> d[6] >> d[7]) {
        set<point> s;
        point q;
        for (int i = 0; i < 4; i++) {
            point r(d[2*i], d[2*i + 1]);
            if (s.count(r) > 0) {
                q = r;
                s.erase(r);
            } else s.insert(r);
        }

        point p = *s.begin(), r = *(++s.begin()); // q is the common endpoint of both segments
        vec v1 = toVec(q, p);
        vec v2 = toVec(q, r);
        point p4 = translate(translate(q, v1), v2);

        printf("%.3f %.3f\n", p4.x, p4.y);
    }

    return 0;
}