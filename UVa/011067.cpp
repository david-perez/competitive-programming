#include <iostream>

using namespace std;

int grid[101][101];

int main() {
    int w, h;
    while (cin >> w >> h && !(w == 0 && h == 0)) {
        for (int x = 0; x <= w; x++)
            for (int y = 0; y <= h; y++)
                grid[x][y] = 0;

        int n;
        cin >> n;
        while (n--) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = -1;
        }

        grid[0][0] = 1;
        for (int x = 0; x <= w; x++)
            for (int y = 0; y <= h; y++) {
                if (grid[x][y] == -1) continue;

                // move right
                int i = x + 1, j = y;
                if (i <= w && grid[i][j] >= 0)
                    grid[i][j] += grid[x][y];

                // move up
                i = x, j = y + 1;
                if (j <= h && grid[i][j] >= 0)
                    grid[i][j] += grid[x][y];
            }

        if (grid[w][h] == 1) cout << "There is one path from Little Red Riding Hood's house to her grandmother's house." << endl;
        else if (grid[w][h] > 1) printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n", grid[w][h]);
        else cout << "There is no path." << endl;
    }

    return 0;
}