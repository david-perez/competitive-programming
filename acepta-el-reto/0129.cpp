#include <iostream>

using namespace std;

int main() {
    int a[11][7] = {
            {1,1,1,1,1,1,0},
            {0,1,1,0,0,0,0},
            {1,1,0,1,1,0,1},
            {1,1,1,1,0,0,1},
            {0,1,1,0,0,1,1},
            {1,0,1,1,0,1,1},
            {1,0,1,1,1,1,1},
            {1,1,1,0,0,0,0},
            {1,1,1,1,1,1,1},
            {1,1,1,1,0,1,1},
            {0,0,0,0,0,0,0} // blank
    };

    int adjMat[11][11];
    for (int u = 0; u < 11; u++)
        for (int v = u; v < 11; v++) {
            int cnt = 0;
            for (int k = 0; k < 7; k++)
                if (a[u][k] != a[v][k]) cnt++;
            adjMat[u][v] = adjMat[v][u] = cnt;
        }

    int n;
    while (cin >> n && n != -1) {
        int N = 1, cnt = adjMat[10][n], m;
        while (cin >> m && m != -1) {
            N++;
            cnt += adjMat[n][m];
            n = m;
        }
        cnt += adjMat[n][10];

        cout << N*cnt << endl;
    }

    return 0;
}
