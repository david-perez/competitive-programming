#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define EPS 1e-9

struct point {
    double x, y;
    point() {
        x = y = 0.0;
    }

    point(double _x, double _y) : x(_x), y(_y) {}

    // to sort points lexicographically
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

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) >= 0;
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

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double perimeter(vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < P.size()-1; i++) // remember that P[0] == P[n-1]
        result += dist(P[i], P[i+1]);
    return result;
}

int main() {
    int N;
    for (int t = 1; cin >> N && N != 0; t++) {
        if (t > 1) cout << endl;

        vector<point> v;
        while (N--) {
            double x, y;
            cin >> x >> y;
            v.push_back(point(x, y));
        }

        vector<point> H = andrew(v);

        printf("Region #%d:\n", t);
        for (int i = H.size()-1; i > 0; i--) // clockwise order / there are no test cases with only one trap
            printf("(%.1f,%.1f)-", H[i].x, H[i].y);
        printf("(%.1f,%.1f)\n", H[0].x, H[0].y);
        printf("Perimeter length = %.2f\n", perimeter(H));
    }

    return 0;
}