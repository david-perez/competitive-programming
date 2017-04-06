#include <iostream>
#include <cstring>

using namespace std;

int memo[71][71];

int F(int n, int t, int P) {
    if (n == 0 && t == 0) return 1;
    if (n == 0) return 0;

    if (memo[n][t] != -1) return memo[n][t];

    int sum = 0;
    for (int p = P; p <= t; p++)
        sum += F(n - 1, t - p, P);

    return memo[n][t] = sum;
}

int main() {
    int K;
    cin >> K;
    while (K--) {
        int N, T, P;
        cin >> N >> T >> P;
        memset(memo, -1, sizeof memo);
        cout << F(N, T, P) << endl;
    }

    return 0;
}