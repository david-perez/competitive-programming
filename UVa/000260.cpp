#include <iostream>

using namespace std;

char grid[200][200];
int N;

int dr[] = {-1,-1,0,0,1,1};
int dc[] = {-1,0,-1,1,0,1};

bool white(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    if (grid[r][c] != 'w') return false;
    if (c == N-1) return true;
    grid[r][c] = 'x';
    for (int d = 0; d < 6; d++)
        if (white(r + dr[d], c + dc[d]))
            return true;
    return false;
}

int main() {
    for (int t = 1; cin >> N && N != 0; t++) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> grid[i][j];

        bool white_wins = false;
        for (int i = 0; i < N; i++)
            if (white(i, 0)) {
                white_wins = true;
                break;
            }

        printf("%d %c\n", t, (white_wins ? 'W' : 'B'));
    }

    return 0;
}