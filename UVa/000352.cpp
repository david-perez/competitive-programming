#include <iostream>

using namespace std;

int N;
int grid[25][25];

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int floodfill(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return 0;
    if (grid[r][c] != 1) return 0;
    int ans = 1;
    grid[r][c] = 0;
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d]);
    return ans;
}

int main() {
    for (int t = 1; cin >> N; t++) {
        cin.get();
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            for (int j = 0; j < N; j++)
                grid[i][j] = s[j] - '0';
        }

        int eagles = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] == 1) {
                    floodfill(i, j);
                    eagles++;
                }

        printf ("Image number %d contains %d war eagles.\n", t, eagles);
    }

    return 0;
}