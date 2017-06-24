#include <iostream>
#include <vector>
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

int N, M;
vector<pair<int, ii>> edgeList;

int kruskal() {
    sort(edgeList.begin(), edgeList.end());
    int mst_cost = 0;
    ufds uf(N);

    for (int i = 0; i < M && uf.numSets != 1; i++) {
        pair<int, ii> front = edgeList[i];
        if (!uf.isSameSet(front.second.first, front.second.second)) {
            mst_cost += front.first;
            uf.unionSet(front.second.first, front.second.second);
        }
    }

    return mst_cost;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        edgeList.clear();
        int V = 0;
        map<string, int> m;

        for (int i = 0; i < M; i++) {
            string s, t;
            int w;
            cin >> s >> t >> w;
            if (m.count(s) == 0) m[s] = V++;
            if (m.count(t) == 0) m[t] = V++;
            int u = m[s], v = m[t];
            edgeList.push_back(make_pair(w, ii(u, v)));
        }

        cout << kruskal() << endl;
        if (T > 0) cout << endl;
    }

    return 0;
}
