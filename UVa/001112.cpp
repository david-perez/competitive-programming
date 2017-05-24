#include <iostream>

using namespace std;

#define INF 1000000000 // 10^9

int N, adjMat[100][100];

void floyd() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main() {
    int nc;
    cin >> nc;
    while (nc--) {
        int E, T, M;
        cin >> N >> E >> T >> M;
        for (int u = 0; u < N; u++)
            for (int v = 0; v < N; v++)
                adjMat[u][v] = u == v ? 0 : INF;

        while (M--) {
            int a, b, e;
            cin >> a >> b >> e;
            a--, b--;
            adjMat[a][b] = e;
        }

        floyd();

        E--;
        int cnt = 0;
        for (int u = 0; u < N; u++)
            if (adjMat[u][E] <= T)
                cnt++;

        cout << cnt << endl;
        if (nc > 0) cout << endl;
    }
}
