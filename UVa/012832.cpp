#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

struct frac {
    ll n, d;

    frac() : n(0), d(1) { };

    frac(ll _n, ll _d) : n(_n), d(_d) {
        simplify();
    }

    void add(struct frac &o) {
        n = n*o.d + o.n*d;
        d *= o.d;
        simplify();
    }

    void simplify() {
        ll g = gcd(n, d);
        n /= g, d /= g;
    }
};

// https://en.wikipedia.org/wiki/Poisson_binomial_distribution
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int m;
        cin >> m;
        frac sol;
        for (int i = 0; i < m; i++) {
            int ni, ki;
            cin >> ni >> ki;
            frac f(ki, ni);
            sol.add(f);
        }

        printf("Case %d: %lld/%lld\n", t, sol.n, sol.d);
    }

    return 0;
}
