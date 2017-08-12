#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int grid[8][8], si, sj, ti, tj;
int dr[8] = {-2,-1,1,2,2,1,-1,-2};
int dc[8] = {1,2,2,1,-1,-2,-2,-1};

void bfs(int i, int j) {
    queue<ii> q;
    grid[i][j] = 0;
    q.push(ii(i, j));
    while (!q.empty()) {
        ii u = q.front(); q.pop();
        int i = u.first, j = u.second;
        for (int d = 0; d < 8; d++) {
            int ni = i + dr[d], nj = j + dc[d];
            if (0 <= ni && ni < 8 && 0 <= nj && nj < 8 && grid[ni][nj] == -1) {
                grid[ni][nj] = grid[i][j] + 1;
                if (ni == ti && nj == tj) return;
                q.push(ii(ni, nj));
            }
        }
    }
}

int main() {
    string s, t;
    while (cin >> s >> t) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                grid[i][j] = -1;

        si = s[0] - 'a';
        sj = s[1] - '1';
        ti = t[0] - 'a';
        tj = t[1] - '1';

        bfs(si, sj);

        printf("To get from %s to %s takes %d knight moves.\n", s.c_str(), t.c_str(), grid[ti][tj]);
    }
}
