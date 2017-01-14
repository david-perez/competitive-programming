#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll N;
    for (int t = 1; cin >> N && N != 0; t++) {
        ll n = (3 + sqrt(9 + 8*N)) / 2;
        if (N != (n*(n-3)) / 2)
            n++;

        printf("Case %d: %lld\n", t, n);
    }

    return 0;
}