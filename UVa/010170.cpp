#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll S, D;
    while (cin >> S >> D) {
        ll t = (int) (-S + 0.5 * (sqrt(4*S*S + 8*D - 4*S + 1) -1));
        if (D == (t+1)*S + (t*(t+1))/2) cout << S + t << endl;
        else cout << S + t + 1 << endl;
    }

    return 0;
}