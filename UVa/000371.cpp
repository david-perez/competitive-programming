#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

ll f(ll n) {
    if (n % 2 == 0) return n / 2;
    else return 3*n + 1;
}

map<ll, ll> m; // cache

ll len(ll n) {
    if (n == 1) return 0;
    if (m.count(n) > 0) return m[n];
    return m[n] = len(f(n)) + 1;
}

int main() {
    ll A, B;
    while (cin >> A >> B && !(A == 0 && B == 0)) {
        ll L = min(A, B), H = max(A, B);
        ll V = 0, S = -1;
        for (ll n = L; n <= H; n++) {
            ll l;
            if (n == 1) l = 3;
            else l = len(n);

            if (l > S) {
                V = n;
                S = l;
            }
        }

        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", L, H, V, S);
    }

    return 0;
}