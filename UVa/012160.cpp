#include <iostream>
#include <queue>

using namespace std;

int r[10], d[10000], R;

int bfs(int u, int U) {
    fill(d, d + 10000, -1);
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front(); q.pop();
        if (u == U) return d[u];
        else {
            for (int i = 0; i < R; i++) {
                int v = (u + r[i]) % 10000;
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    return -1;
}

int main() {
    int L, U, t = 1;
    while (cin >> L >> U >> R && !(L == 0 && U == 0 && R == 0)) {
        for (int i = 0; i < R; i++) cin >> r[i];

        printf("Case %d: ", t++);
        int moves = bfs(L, U);
        if (moves == -1) cout << "Permanently Locked" << endl;
        else cout << moves << endl;
    }

    return 0;
}
