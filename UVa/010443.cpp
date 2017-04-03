#include <iostream>

using namespace std;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool wins(char x, char y) {
    return (x == 'P' && y == 'R') || (x == 'R' && y == 'S') || (x == 'S' && y == 'P');
}

int main() {
    char g[2][100][100];
    int t;
    cin >> t;
    while (t--) {
        int r, c, n;
        cin >> r >> c >> n;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                cin >> g[0][i][j];
                g[1][i][j] = g[0][i][j];
            }

        int k = 0;
        while (n--) {
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++) {
                    bool m = false;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dr[d];
                        int nj = j + dc[d];
                        if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
                        if (wins(g[k][ni][nj], g[k][i][j])) {
                            g[1-k][i][j] = g[k][ni][nj];
                            m = true;
                            break;
                        }
                    }
                    if (!m) g[1-k][i][j] = g[k][i][j];
                }
            k = 1-k;
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << g[k][i][j];
            cout << endl;
        }

        if (t > 0) cout << endl;
    }

    return 0;
}