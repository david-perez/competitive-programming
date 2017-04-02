#include <iostream>

using namespace std;

typedef long long ll;

ll dp[21][21];

ll nCm(int n, int m) {
    if (n == m || m == 0) return 1;
    if (dp[n][m] != -1) return dp[n][m];
    return dp[n][m] = nCm(n-1, m-1) + nCm(n-1, m);
}

int main() {
    for (int n = 0; n <= 20; n++)
        for (int m = 0; m <= n; m++)
            dp[n][m] = -1;

    ll D[21];
    D[0] = 1; D[1] = 0;
    for (int n = 2; n <= 20; n++)
        D[n] = (n-1) * (D[n-1] + D[n-2]);

    int N, M;
    while (cin >> N >> M) {
        ll res = 0;
        for (int m = 0; m <= M; m++)
            res += nCm(N, m) * D[N-m];
        cout << res << endl;
    }

    return 0;
}