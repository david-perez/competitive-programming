#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int T;
    cin >> T;
    for (int X = 1; X <= T; X++) {
        int N, L;
        cin >> N >> L;
        vi mangoes;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            mangoes.push_back(x);
            sum += x;
        }

        bool b = true;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            b &= x >= mangoes[i];
        }

        printf("Case %d: %s\n", X, sum <= L && b ? "Yes" : "No");
    }

    return 0;
}