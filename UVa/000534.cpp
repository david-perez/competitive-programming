#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct point {
    int x, y;

    point() { x = 0, y = 0; }
    point(int _x, int _y) : x(_x), y(_y) { }
};

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<pair<int, ii>> viii;

struct ufds {
    vi p, r;
    int numSets;

    ufds(int N) {
        p.assign(N, 0); r.assign(N, 0); numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet(int i) { // finds and path compresses if possible
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (r[x] > r[y]) p[y] = x;
            else {
                p[x] = y;
                if (r[x] == r[y]) r[y]++;
            }
            numSets--;
        }
    }
};

int distSq(point &p, point &q) {
    int dy = q.y - p.y, dx = q.x - p.x;
    return dx*dx + dy*dy;
}

int main() {
    int n;
    for (int t = 1; cin >> n && n != 0; t++) {
        vector<point> pts;
        viii edgeList;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            pts.push_back({x, y});
            for (int j = 0; j <= i; j++) edgeList.push_back(make_pair(distSq(pts[i], pts[j]), ii(i, j)));
        }

        sort(edgeList.begin(), edgeList.end());
        ufds uf(n);
        int frogD = 0;
        for (int i = 0; i < edgeList.size() && !uf.isSameSet(0, 1); i++) {
            iii e = edgeList[i];
            int w = e.first, u = e.second.first, v = e.second.second;
            if (!uf.isSameSet(u, v)) {
                uf.unionSet(u, v);
                frogD = max(frogD, w);
            }
        }

        printf("Scenario #%d\nFrog Distance = %.3f\n\n", t, sqrt(frogD));
    }

    return 0;
}
