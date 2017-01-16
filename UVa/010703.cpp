#include <iostream>
#include <cstring>

using namespace std;

int a[500][500];

int main() {
    int W, H, N;
    while (cin >> W >> H >> N && !(W == 0 && H == 0 && N == 0)) {
        memset(a, 0, sizeof a);
        while (N--) {
            int u1, v1, u2, v2;
            cin >> u1 >> v1 >> u2 >> v2;
            u1--, v1--, u2--, v2--;
            int x1 = min(u1, u2), x2 = max(u1, u2);
            int y1 = min(v1, v2), y2 = max(v1, v2);

            for (int i = x1; i <= x2; i++)
                for (int j = y1; j <= y2; j++)
                    a[i][j] = 1;
        }

        int s = 0;
        for (int i = 0; i < W; i++)
            for (int j = 0; j < H; j++)
                if (a[i][j] == 0)
                    s++;

        if (s == 0) cout << "There is no empty spots." << endl;
        else if (s == 1) cout << "There is one empty spot." << endl;
        else printf("There are %d empty spots.\n", s);
    }

    return 0;
}