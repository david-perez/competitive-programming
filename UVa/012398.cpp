#include <iostream>

using namespace std;

typedef pair<int, int> ii;

int m[3][3];

ii coords(char c) {
    int cell = (c - 'a');
    int row = cell / 3;
    int col = cell - 3*row;
    return ii(row, col);
}

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void addOne(ii p) {
    int i = p.first, j = p.second;
    m[i][j] = (m[i][j] + 1) % 10;
    for (int d = 0; d < 4; d++)
        if (0 <= i + dr[d] && i + dr[d] < 3 && 0 <= j + dc[d] && j + dc[d] < 3)
            m[i + dr[d]][j + dc[d]] = (m[i + dr[d]][j + dc[d]] + 1) % 10;
}

int main() {
    string s;
    for (int t = 1; getline(cin, s); t++) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                m[i][j] = 0;

        if (!s.empty())
            for (int i = s.length()-1; i >= 0; i--)
                addOne(coords(s[i]));

        printf("Case #%d:\n", t);
        for (int i = 0; i < 3; i++)
            printf("%d %d %d\n", m[i][0], m[i][1], m[i][2]);
    }

    return 0;
}