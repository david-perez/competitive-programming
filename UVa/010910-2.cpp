#include <iostream>

using namespace std;

int main() {
    int nCm[71][71];
    for (int n = 0; n <= 70; n++)
        for (int m = 0; m <= n; m++)
            if (m == 0 || n == m) nCm[n][m] = 1;
            else nCm[n][m] = nCm[n-1][m-1] + nCm[n-1][m];

    int K;
    cin >> K;
    while (K--) {
        int N, T, P;
        cin >> N >> T >> P;
        cout << (P*N > T ? 0 : nCm[T-(P-1)*N-1][N-1]) << endl;
    }

    return 0;
}