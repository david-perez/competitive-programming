#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
    int x, y;

    point(int _x, int _y) : x(_x), y(_y) {}

    bool operator != (const point other) const {
        return x != other.x || y != other.y;
    }
};

struct vec {
    int x, y;

    vec(int _x, int _y) : x(_x), y(_y) { }
};

vec toVec(point a, point b) {
    return vec(b.x-a.x, b.y-a.y);
}

point pivot(0,0);

int distSq(point p1, point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) == 0;
}

bool angleCmp(point a, point b) {
    if (collinear(pivot, a, b))
        return distSq(pivot, a) < distSq(pivot, b);

    int d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    int d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> graham(vector<point> &P) { // the content of P may be reshuffled
    int n = P.size();
    if (n <= 3) {
        if (P[0] != P[n-1]) P.push_back(P[0]);
        return P; // CH is P itself
    }

    // first, find P0 = point with lowest Y and if tie: leftmost X
    int P0 = 0;
    for (int i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x < P[P0].x))
            P0 = i;

    point temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]

    // second, sort points by angle w.r.t pivot P0
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]

    // third, the ccw tests
    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    int i = 2;
    while (i < n) {
        int j = S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
        else S.pop_back(); // or pop the top of S until we have a left turn
    }

    S.erase(S.begin());
    S.push_back(*S.begin());

    return S;
}

int main() {
    int K;
    cin >> K;
    cout << K << endl;
    while (K--) {
        int N;
        cin >> N;
        vector<point> P;
        while (N--) {
            int x, y;
            cin >> x >> y;
            P.push_back(point(x, y));
        }

        vector<point> ch = graham(P);
        cout << ch.size() << endl;
        for (point &p : ch)
            printf("%d %d\n", p.x, p.y);

        if (K) {
            int delim; cin >> delim; // -1 separating test cases
            cout << -1 << endl;
        }
    }

    return 0;
}