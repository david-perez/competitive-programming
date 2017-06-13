#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
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


int main() {
    int s, c;
    while (cin >> s >> c && !(s == 0 && c == 0)) {
        map<string, int> sti;
        int V = 0;
        while (s--) {
            string t;
            cin >> t;
            if (sti.count(t) == 0) sti[t] = V++;
        }

        viii edgeList;
        while (c--) {
            int w;
            string x, y;
            cin >> x >> y >> w;
            int u = sti[x], v = sti[y];
            edgeList.push_back(make_pair(w, ii(u, v)));
        }
        string x; cin >> x; // Peter's home.

        sort(edgeList.begin(), edgeList.end());

        int W = 0;
        ufds uf(V);
        for (int i = 0; i < edgeList.size() && uf.numSets != 1; i++) {
            int w = edgeList[i].first, u = edgeList[i].second.first, v = edgeList[i].second.second;
            if (!uf.isSameSet(u, v)) {
                W += w;
                uf.unionSet(u, v);
            }
        }

        if (uf.numSets != 1) cout << "Impossible" << endl;
        else cout << W << endl;
    }

    return 0;
}
