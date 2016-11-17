#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

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
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        ufds uf(N);

        while (M--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            uf.unionSet(u, v);
        }

        vi sets(N, -1);
        for (int i = 0; i < N; i++)
            sets[i] = uf.findSet(i);

        vi v(N, 0);
        for (int &s : sets)
            v[s]++;
        sort(v.begin(), v.end(), greater<int>());
        cout << v[0] << endl;
    }

    return 0;
}