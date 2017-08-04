#include <iostream>

using namespace std;

int dr[] = {1,1,1,0};
int dc[] = {-1,0,1,1};

int main() {
    char g[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> g[i][j];

    bool wins = false;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int d = 0; d < 4; d++) {
                int crosses = 0, empty = 0, fi = i + 4*dr[d], fj = j + 4*dc[d];
                if (fi >= 10 || fj < 0 || fj >= 10) continue;
                for (int ni = i, nj = j; !(ni == fi + dr[d] && nj == fj + dc[d]); ni = ni + dr[d], nj = nj + dc[d]) {
                    if (g[ni][nj] == 'X') crosses++;
                    else if (g[ni][nj] == '.') empty++;
                }

                if (crosses == 4 && empty == 1) {
                    wins = true;
                    goto done;
                }
            }

done:
    cout << (wins ? "YES" : "NO") << endl;

    return 0;
}
