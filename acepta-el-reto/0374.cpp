#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll x;
        cin >> x;

        ll M = x, m = x;
        ll MM = 1, mm = 1;

        while (cin >> x && x != 0) {
            if (x > M) {
                M = x;
                MM = 1;
            } else if (x == M) MM++;

            if (x < m) {
                m = x;
                mm = 1;
            } else if (x == m) mm++;
        }

        printf("%lld %lld %lld %lld\n", m, mm, M, MM);
    }

    return 0;
}