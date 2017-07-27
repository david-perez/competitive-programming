#include <iostream>
#include <queue>
#include <map>

using namespace std;

int M, N, g[50][50], dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

struct state {
    int x, y, o;

    void go() {
        x += dr[o], y += dc[o];
    }

    void turnL() {
        o = (o + 3) % 4;
    }

    void turnR() {
        o = (o + 1) % 4;
    }

    bool operator <(const state &other) const {
        return x < other.x ||
               (x == other.x && y < other.y) ||
               (x == other.x && y == other.y && o < other.o);
    }
};

map<state, int> d;

bool is_valid(state u) {
    return 0 <= u.x && u.x <= M-2 &&
           0 <= u.y && u.y <= N-2 &&
           g[u.x][u.y] == 0 &&
           g[u.x][u.y+1] == 0 &&
           g[u.x+1][u.y] == 0 &&
           g[u.x+1][u.y+1] == 0;
}

int bfs(state u, int E1, int E2) {
    d[u] = 0;
    queue<state> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front(); q.pop();
        if (u.x == E1 && u.y == E2) return d[u];

        state tL = u; tL.turnL();
        if (d.count(tL) == 0) {
            d[tL] = d[u] + 1;
            q.push(tL);
        }

        state tR = u; tR.turnR();
        if (d.count(tR) == 0) {
            d[tR] = d[u] + 1;
            q.push(tR);
        }

        state goN = u;
        for (int n = 1; n <= 3; n++) {
            goN.go();
            if (!is_valid(goN)) break;
            else if (d.count(goN) == 0) {
                d[goN] = d[u] + 1;
                q.push(goN);
            }
        }
    }

    return -1;
}

int main() {
    while (cin >> M >> N && !(M == 0 && N == 0)) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> g[i][j];
        int B1, B2, E1, E2, o;
        string s;
        cin >> B1 >> B2 >> E1 >> E2 >> s;
        B1--, B2--, E1--, E2--;
        if (s == "north") o = 0;
        else if (s == "east") o = 1;
        else if (s == "south") o = 2;
        else o = 3;

        d.clear();
        cout << bfs({B1, B2, o}, E1, E2) << endl;
    }

    return 0;
}
