#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int g[2001][2001], dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
queue<ii> q;

int bfs() {
    while (!q.empty()) {
        ii u = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            ii v = ii(u.first + dr[d], u.second + dc[d]);
            if (0 <= v.first && v.first < 2001 && 0 <= v.second && v.second < 2001) {
                if (g[v.first][v.second] == -1) return g[u.first][u.second] + 1;
                else if (g[v.first][v.second] == -2) {
                    g[v.first][v.second] = g[u.first][u.second] + 1;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    int p;
    while (cin >> p && p != 0) {
        for (int i = 0; i < 2001; i++)
            for (int j = 0; j < 2001; j++)
                g[i][j] = -2;

        q = queue<ii>();
        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            g[x][y] = 0;
            q.push(ii(x, y));
        }

        cin >> p;
        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            g[x][y] = -1;
        }

        cout << bfs() << endl;
    }

    return 0;
}
