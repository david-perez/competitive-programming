#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>

using namespace std;

typedef vector<int> vi;

struct point {
    point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    int x, y, z;
};

double dist(point &p1, point &p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    int dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    vector<point> pts;
    int x, y, z;
    while (cin >> x >> y >> z && !(x == 0 && y == 0 && z == 0))
        pts.push_back(point(x, y, z));

    vi h(10, 0);
    for (int u = 0; u < pts.size(); u++) {
        point p1 = pts[u];

        // find nearest neighbor of p1
        double minDist = DBL_MAX;
        for (int v = 0; v < pts.size(); v++) {
            point p2 = pts[v];
            if (u != v && dist(p1, p2) < minDist)
                minDist = dist(p1, p2);
        }

        if (minDist < 10) {
            int i = (int) (minDist);
            h[i]++;
        }
    }

    for (int &s : h)
        printf("%4d", s);
    cout << endl;

    return 0;
}