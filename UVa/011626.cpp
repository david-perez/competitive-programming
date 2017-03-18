#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct point {
    int x, y;
    point() {
        x = y = 0;
    }

    point(int _x, int _y) : x(_x), y(_y) {}

    bool operator < (point other) const { // sort points lexicographically
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

ll cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

// use >= to accept collinear points in the convex hull
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

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<point> H;
        int n;
        cin >> n;
        while (n--) {
            int x, y;
            char c;
            cin >> x >> y >> c;
            if (c == 'Y') H.push_back(point(x, y));
        }

        // It's easier to get the convex hull of the given points (which is returned in ccw order) than to
        // order the points in ccw order dealing correctly with collinear points.
        H = andrew(H);
        H.pop_back();
        cout << H.size() << endl;
        for (point &p: H)
            printf("%d %d\n", p.x, p.y);
    }

    return 0;
}