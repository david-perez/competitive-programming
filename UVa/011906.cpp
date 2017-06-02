#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> ii;

int R, C, M, N, g[100][100], ans[2];

void dfs(int r, int c) {
    g[r][c] = 0;

    set<ii> s; // We need to remove duplicate moves that arise when M or N is zero.
    for (int k = 0; k < 2; k++)
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++) {
                if (i == 0 || j == 0) continue;

                int m, n;
                if (k == 0) m = i * M, n = j * N;
                else m = i * N, n = j * M;
                int rr = r + m, cc = c + n;
                if (rr < 0 || rr >= R || cc < 0 || cc >= C || g[rr][cc] == -2) continue;

                s.insert(ii(rr, cc));
            }

    for (const ii &p : s) {
        int rr = p.first, cc = p.second;
        g[r][c]++;
        if (g[rr][cc] == -1) dfs(rr, cc);
    }

    ans[g[r][c] % 2]++;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int W;
        cin >> R >> C >> M >> N >> W;
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                g[r][c] = -1;

        while (W--) {
            int r, c;
            cin >> r >> c;
            g[r][c] = -2;
        }

        ans[0] = ans[1] = 0;
        dfs(0, 0);

        printf("Case %d: %d %d\n", t, ans[0], ans[1]);
    }
    
    return 0;
}
