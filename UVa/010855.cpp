#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> vvc;

int N, n;

bool equal(vvc &M, vvc &m, int i, int j) {
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            if (M[i + u][j + v] != m[u][v]) return false;

    return true;
}

void rotate90cw(vvc &m) {
    int n = m.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(m[i][j], m[j][i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n/2; j++)
            swap(m[i][j], m[i][n - 1 - j]);
}

int main() {
    while (cin >> N >> n && !(N == 0 && n == 0)) {
        vvc M(N, vector<char>()), m(n, vector<char>());

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                M[i].push_back(c);
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                m[i].push_back(c);
            }

        int cnt[4] = {0, 0, 0, 0};
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i + n <= N; i++)
                for (int j = 0; j + n <= N; j++)
                    if (equal(M, m, i, j)) cnt[k]++;

            if (k < 3) rotate90cw(m);
        }

        printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
    }

    return 0;
}
