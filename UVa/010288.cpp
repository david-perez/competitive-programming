#include <iostream>

using namespace std;

typedef long long ll;

int ndigits(ll n) {
    int cnt = 0;
    do {
        cnt++;
        n /= 10;
    } while (n);

    return cnt;
}

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

    frac() { n = 0, d = 1; }
    
    frac(ll num, ll den) {
        n = num;
        d = den;
    }

    void add(frac f) {
        n = n*f.d + d*f.n;
        d *= f.d;
        ll g = gcd(n, d);
        n /= g, d /= g;
    }

    void mult(ll m) {
        n *= m;
        ll g = gcd(n, d);
        n /= g, d /= g;
    }

    void print() {
        ll z = n / d;
        ll n2 = n - z*d;
        if (n2 == 0) {
            printf("%lld\n", z);
            return;
        }

        int digd = ndigits(d), digz = ndigits(z);
        printf("%*s %lld\n", digz, "",  n2);
        printf("%lld %s\n", z, string(digd,'-').c_str());
        printf("%*s %lld\n", digz, "",  d);
    }
};

int main() {
    frac sols[34];
    frac Hn = frac();
    for (int n = 1; n <= 33; n++) {
        Hn.add(frac(1, n));
        frac nHn = Hn;
        nHn.mult(n);
        sols[n] = nHn;
    }

    int n;
    while (cin >> n)
        sols[n].print();
    
    return 0;
}
