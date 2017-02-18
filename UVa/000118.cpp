#include <iostream>
#include <algorithm>

using namespace std;

int grid[51][51];
int W, H, x, y, o; // o = current orientation
char dir[4] = {'N', 'E', 'S', 'W'};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool execute(char &c) {
    if (c == 'F') {
        int newX = x + dx[o];
        int newY = y + dy[o];
        if (newX < 0 || W < newX || newY < 0 || H < newY) {
            if (grid[x][y] == 0) { // no scent => get lost
                grid[x][y]++;
                return true;
            }
        } else {
            x = newX;
            y = newY;
        }
    } else if (c == 'R') o = (o + 1) % 4;
    else if (o == 0) o = 3;
    else o--;

    return false;
}

int main() {
    cin >> W >> H;
    for (int x = 0; x <= W; x++)
        for (int y = 0; y <= H; y++)
            grid[x][y] = 0; // no robot fell off from (x, y)

    char c;
    while (cin >> x >> y >> c) {
        o = (int) distance(dir, find(dir, dir+4, c));
        string s;
        cin >> s;
        bool lost = false;
        for (int i = 0; i < s.length() && !lost; i++)
            lost = execute(s[i]);

        printf("%d %d %c", x, y, dir[o]);
        if (lost) cout << " LOST";
        cout << endl;
    }

    return 0;
}