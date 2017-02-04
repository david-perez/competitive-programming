#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

#define EPS 1e-9

struct point {
    double x, y;

    point() {
        x = y = 0.0;
    }

    point(double _x, double _y) : x(_x), y(_y) {}
};

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
    return v.x*v.x + v.y*v.y;
}

double angle(vec u, vec v) {
    return acos(dot(u, v) / sqrt(norm_sq(u) * norm_sq(v)));
}

double dist(point p, point q) {
    double dx = q.x - p.x;
    double dy = q.y - p.y;
    return sqrt(dx*dx + dy*dy);
}

double distToLine(point p, point a, point b) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    point c = translate(a, scale(ab, u));
    return dist(p, c);
}

// Returns the distance from p to the segment defined by two points a and b.
double distToSegment(point p, point a, point b) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) return dist(p, a);
    if (u > 1.0) return dist(p, b);
    return distToLine(p, a, b);
}

// Returns true if the segment given by points p and q cuts the circle x^2 + y^2 = r^2 in two distinct points.
bool cutsCircle(point p, point q, double r) {
    return distToSegment(point(), p, q) < r;
}

// Returns in the array pt, the two tangent points of the tangents to the
// circle x^2 + y^2 = r^2 from the point p, which lies outside the circle.
void tangentPoints(point p, double r, point pt[]) {
    double p0 = p.x, p1 = p.y;
    double den = p0*p0 + p1*p1;
    double dis = sqrt(p0*p0 + p1*p1 - r*r);
    pt[0] = point((p0*r*r - dis*p1*r)/den, (p1*r*r + dis*p0*r)/den);
    pt[1] = point((p0*r*r + dis*p1*r)/den, (p1*r*r - dis*p0*r)/den);
}

// Returns the arc-length that joins the points p and q, which lie on the circle x^2 + y^2 = r^2.
double distC(point &p, point &q, double r) {
    vec u = toVec(point(), p), v = toVec(point(), q);
    return angle(u, v) * r;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        double x1, y1, x2, y2, r;
        cin >> x1 >> y1 >> x2 >> y2 >> r;
        point p(x1, y1), q(x2, y2);

        if (!cutsCircle(p, q, r)) printf("%.3f\n", dist(p, q));
        else {
            point pts[2], qts[2];
            tangentPoints(p, r, pts);
            tangentPoints(q, r, qts);

            double minD = DBL_MAX;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    minD = min(minD, dist(p, pts[i]) + distC(pts[i], qts[j], r) + dist(qts[j], q));

            printf("%.3f\n", minD);
        }
    }

    return 0;
}