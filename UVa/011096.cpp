#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

struct point {
    int x, y;

    point() {
        x = y = 0;
    }

    point(int _x, int _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

struct vec {
    ll x, y;

    vec(ll _x, ll _y) : x(_x), y(_y) { }
};

vec toVec(point a, point b) {
    return vec(b.x-a.x, b.y-a.y);
}

// We have to use long long for vec; otherwise cross() performs int overflow and we get WA!
// An alternative is to use double for all of our computational geometry, which also gets AC.
ll cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
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

double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < P.size()-1; i++) // remember that P[0] == P[n-1]
        result += dist(P[i], P[i+1]);
    return result;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int l, n;
        cin >> l >> n;
        vector<point> P;
        while (n--) {
            int x, y;
            cin >> x >> y;
            P.push_back(point(x, y));
        }

        printf("%.5f\n", max((double) l, perimeter(andrew(P))));
    }
}