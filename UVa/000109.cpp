#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

#define PI acos(-1)
#define EPS 1e-9

struct point {
    int x, y;
    point() {
        x = y = 0;
    }

    point(int _x, int _y) : x(_x), y(_y) {}

    // to sort points lexicographically
    bool operator < (point other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

struct vec {
    int x, y;
    vec(int _x, int _y) : x(_x), y(_y) { }
};

vec toVec(point a, point b) {
    return vec(b.x-a.x, b.y-a.y);
}

int dot(vec a, vec b) {
    return a.x*b.x + a.y*b.y;
}

int norm_sq(vec v) {
    return v.x*v.x + v.y*v.y;
}

int cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

double angle(point a, point o, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

bool inPolygon(point pt, const vector<point> &P) {
    if (P.size() <= 3) return false;
    double sum = 0;
    for (int i = 0; i < P.size() - 1; i++) {
        if (ccw(pt, P[i], P[i + 1])) sum += angle(P[i], pt, P[i + 1]);
        else sum -= angle(P[i], pt, P[i + 1]);
    }
    return fabs(fabs(sum) - 2*PI) < EPS;
}

vector<point> andrew(vector<point> &P) {
    int n = P.size(), k = 0;
    vector<point> H(2*n);

    sort(P.begin(), P.end());

    // Build lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && !ccw(H[k-2], H[k-1], P[i])) k--;
        H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && !ccw(H[k-2], H[k-1], P[i])) k--;
        H[k++] = P[i];
    }

    H.resize(k);
    return H;
}

double area(const vector<point> &P) {
    int result = 0, x1, y1, x2, y2;
    for (int i = 0; i < P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return ((double) abs(result)) / 2;
}

int main() {
    int N;
    set<vector<point>> kingdoms;
    while (cin >> N && N != -1) {
        vector<point> v;
        while (N--) {
            int x, y;
            cin >> x >> y;
            v.push_back(point(x, y));
        }
        kingdoms.insert(andrew(v));
    }

    int x, y;
    double result = 0;
    while (cin >> x >> y) {
        point pt(x, y);
        auto it = kingdoms.begin();
        while (it != kingdoms.end()) {
            if (inPolygon(pt, *it)) {
                result += area(*it);
                it = kingdoms.erase(it);
            } else ++it;
        }
    }

    printf("%.2f\n", result);

    return 0;
}