#include <iostream>

using namespace std;

int c, K, a[10000];

int f(int i, int j) {
    if (c > K) return c;
    if (i >= j) return 0;

    if (a[i] == a[j]) return f(i+1, j-1);
    c++;
    int D = 1 + min(f(i+1, j), f(i, j-1));
    c--;
    return D;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N >> K;
        for (int i = 0; i < N; i++)
            cin >> a[i];

        c = 0;
        int D = f(0, N-1);
        printf("Case %d: ", t);
        if (D == 0) cout << "Too easy" << endl;
        else if (D > K) cout << "Too difficult" << endl;
        else cout << D << endl;
    }

    return 0;
}
