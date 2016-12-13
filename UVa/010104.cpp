#include <iostream>

using namespace std;

typedef long long ll;

ll eea(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0, yy = x = 1;
    while (b) {
        ll q = a/b, t = b; b = a%b; a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t;
    }
    return a;
}

int main() {
    ll a, b;
    while (cin >> a >> b) {
        ll x, y;
        ll d = eea(a, b, x, y);
        printf("%lld %lld %lld\n", x, y, d);
    }

    return 0;
}