#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

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

struct edge {
    ii p, q;
    double d;

    bool operator < (edge other) const {
        return d < other.d;
    }
};

double dist(ii p, ii q) {
    int dx = p.first - q.first;
    int dy = p.second - q.second;
    return sqrt(dx*dx + dy*dy);
}

vector<edge> edgeList;
map<ii, int> m;
int n, r, states;
double mst_r, mst_rr;

void kruskal() {
    sort(edgeList.begin(), edgeList.end());
    mst_r = 0;
    mst_rr = 0;
    states = 1;
    ufds uf(n);

    for (int i = 0; i < edgeList.size() && uf.numSets != 1; i++) {
        edge front = edgeList[i];
        if (!uf.isSameSet(m[front.p], m[front.q])) {
            if (front.d > r) {
                states++;
                mst_rr += front.d;
            } else mst_r += front.d;

            uf.unionSet(m[front.p], m[front.q]);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> r;
        edgeList.clear();
        m.clear();
        int ms = 0;

        vector<ii> cities;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ii city = ii(x, y);
            m[city] = ms++;
            cities.push_back(city);

            for (ii &c : cities) {
                edge e;
                e.p = c;
                e.q = city;
                e.d = dist(e.p, e.q);
                edgeList.push_back(e);
            }
        }

        kruskal();
        printf("Case #%d: %d %d %d\n", t, states, (int) (mst_r + 0.5), (int) (mst_rr + 0.5));
    }

    return 0;
}