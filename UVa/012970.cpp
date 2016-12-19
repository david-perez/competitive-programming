#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ll v1, d1, v2, d2;
    for (int t = 1; cin >> v1 >> d1 >> v2 >> d2 && !(v1 == 0 && d1 == 0 && v2 == 0 && d2 == 0); t++) {
        printf("Case #%d: %s\n", t, (v2*d1 < v1*d2 ? "You owe me a beer!" : "No beer for the captain."));

        ll num = v1*d2 + v2*d1;
        ll den = 2*v1*v2;
        ll _gcd = gcd(max(num, den), min(num, den));
        num /= _gcd, den /= _gcd;
        printf("Avg. arrival time: %lu", num);
        if (den == 1) cout << endl;
        else printf("/%lu\n", den);
    }

    return 0;
}