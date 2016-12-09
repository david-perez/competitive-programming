#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

double dist(ii p, ii q) {
    int dy = q.second - p.second;
    int dx = q.first - p.first;
    return sqrt(dx*dx + dy*dy);
}

int N, M;
vvi adjList;
vi match, vis;

int aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < adjList[l].size(); j++) {
        int r = adjList[l][j];
        if (match[r] == -1 || aug(match[r])) {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int berge_mcbm() {
    int mcbm = 0;
    match.assign(N+M, -1);
    vis.assign(M, 0);
    for (int l = 0; l < M; l++) {
        vis.assign(M, 0);
        mcbm += aug(l);
    }

    return mcbm;
}

int main() {
    int L;
    cin >> L;
    while (L--) {
        cin >> N >> M;

        vii bob;
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            bob.push_back(ii(x, y));
        }

        vii dog;
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            dog.push_back(ii(x, y));
        }

        adjList.assign(M, vi());
        for (int i = 0; i < M; i++) {
            ii p = dog[i];
            for (int j = 0; j < N-1; j++) {
                ii q0 = bob[j];
                ii q1 = bob[j+1];
                if (dist(q0, p) + dist(p, q1) <= 2 * dist(q0, q1))
                    adjList[i].push_back(j);
            }
        }

        int mcbm = berge_mcbm();
        int K = N + mcbm;
        cout << K << endl;
        for (int j = 0; j < N-1; j++) {
            ii q = bob[j];
            printf("%d %d ", q.first, q.second);
            if (match[j] != -1) {
                int i = match[j];
                ii p = dog[i];
                printf("%d %d ", p.first, p.second);
            }
        }
        ii q = bob[N-1];
        printf("%d %d\n", q.first, q.second);

        if (L > 0) cout << endl;
    }

    return 0;
}