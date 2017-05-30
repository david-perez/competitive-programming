#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

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

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        viii edgeList;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edgeList.push_back(make_pair(w, ii(u, v)));
        }

        ufds uf(n);
        sort(edgeList.begin(), edgeList.end());
        int range = 0;
        for (int i = 0; i < m && uf.numSets != 1; i++) {
            iii e = edgeList[i];
            int w = e.first, u = e.second.first, v = e.second.second;
            if (!uf.isSameSet(u, v)) {
                uf.unionSet(u, v);
                range = max(range, w);
            }
        }

        if (uf.numSets == 1) cout << range << endl;
        else cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
