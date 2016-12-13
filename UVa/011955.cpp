#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll memo[51][51];

ll binom(int k, int j) {
    if (j == 0 || j == k) return 1;
    if (memo[k][j] != -1) return memo[k][j];
    return memo[k][j] = binom(k-1, j-1) + binom(k-1, j);
}

int main() {
    memset(memo, -1, sizeof memo);

    int T;
    cin >> T; cin.get();
    for (int t = 1; t <= T; t++) {
        printf("Case %d: ", t);

        int k;
        char x[100], y[100];
        scanf("(%[a-z]+%[a-z])^%d\n", x, y, &k);

        for (int j = 0; j <= k; j++) {
            if (j != 0) cout <<'+';

            ll coef = binom(k, j);
            if (coef > 1) cout << coef << '*';
            if (k-j > 0) {
                cout << x;
                if (k-j > 1) cout << '^' << k-j;
            }
            if (j > 0) {
                if (k-j > 0) cout << '*';
                cout << y;
                if (j > 1) cout << '^' << j;
            }
        }

        cout << endl;
    }

    return 0;
}