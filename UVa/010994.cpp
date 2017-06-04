#include <iostream>

using namespace std;

typedef long long ll;

ll h(ll n) {
    if (n <= 0) return 0;
    ll ret = 0;
    while (n != 0) {
        ret += 45 * (n / 10);
        for (ll m = ((n / 10) * 10) + 1; m <= n; m++)
            ret += m % 10;
        n /= 10;
    }

    return ret;
}

int main() {
    ll p, q;
    while (cin >> p >> q && !(p < 0 && q < 0))
        cout << h(q) - h(p-1) << endl;

    return 0;
}
