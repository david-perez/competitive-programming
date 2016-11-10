#include <iostream>
#include <vector>
#include <map>

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

    void print() {
        cout << "p[] = ";
        for (int i = 0; i < p.size(); i++)
            cout << i << " -> " << p[i] << "; ";
        cout << endl;
    }
};

int main() {
    int N, E;
    while (cin >> N >> E) {
        ufds uf(N);
        map<char, int> m;
        int vtx = 0;
        for (int i = 0; i < E; i++) {
            char n1, n2;
            cin >> n1 >> n2;

            if (m.count(n1) == 0)
                m[n1] = vtx++;

            if (m.count(n2) == 0)
                m[n2] = vtx++;

            uf.unionSet(m[n1], m[n2]);
        }

        cout << 1 + uf.numSets + E - N << endl;
    }

    return 0;
}