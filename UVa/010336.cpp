#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
char grid[11][11]; // There are no bounds on H and W in the problem statement, but these values suffice.

struct cmp {
    bool operator() (const pair<char, int> &a, const pair<char, int> &b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }
};

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int floodfill(int i, int j, char c) {
    if (i < 0 || i >= H || j < 0 || j >= W) return 0;
    if (grid[i][j] != c) return 0;
    int ans = 1;
    grid[i][j] = '0';
    for (int d = 0; d < 4; d++)
        ans += floodfill(i + dr[d], j + dc[d], c);
    return ans;
}

int main() {
    int N;
    cin >> N;
    for (int t = 1; t <= N; t++) {
        cin >> H >> W;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> grid[i][j];

        map<char, int> m;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (grid[i][j] != '0') {
                    char c = grid[i][j];
                    floodfill(i, j, c);
                    m[c]++;
                }

        vector<pair<char, int>> v;
        for (auto &p : m)
            v.push_back(p);

        sort(v.begin(), v.end(), cmp());

        printf("World #%d\n", t);
        for (auto &p : v)
            printf("%c: %d\n", p.first, p.second);
    }

    return 0;
}