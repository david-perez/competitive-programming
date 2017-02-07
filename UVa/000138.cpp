#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

void preprocess() {
    for (ll N = 2, cnt = 0; cnt < 10; N++) {
        ll n = (int) sqrt((N*N + N) / 2);
        if (n*n == (N*N + N) / 2) {
            cnt++;
            printf("%10lld%10lld\n", n, N);
        }
    }
}

int main() {
    // preprocess();

    cout << "         6         8\n"
            "        35        49\n"
            "       204       288\n"
            "      1189      1681\n"
            "      6930      9800\n"
            "     40391     57121\n"
            "    235416    332928\n"
            "   1372105   1940449\n"
            "   7997214  11309768\n"
            "  46611179  65918161\n";

    return 0;
}