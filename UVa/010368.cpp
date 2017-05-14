#include <iostream>

using namespace std;

typedef long long ll;

bool minmax(ll a, ll b) {
    if (b == 0) return 0;
    bool ret = false;
    if (a / b > 1) ret = !minmax(b + a % b, b);
    return ret | !minmax(b, a % b);
}

int main() {
    ll x, y;
    while (cin >> x >> y && !(x == 0 && y == 0))
        printf("%s wins\n", minmax(max(x, y), min(x, y)) ? "Stan" : "Ollie");

    return 0;
}
