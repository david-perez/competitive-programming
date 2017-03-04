#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll m, x;
    while (cin >> m >> x && !(m == 0 && x == 0)) {
        if (x == 100) cout << "Not found" << endl;
        else {
            ll v = (100 * (m - 1)) / (100 - x);
            if (v * (100 - x) == 100 * (m - 1)) v--;
            if (m <= v) cout << v << endl;
            else cout << "Not found" << endl;
        }
    }

    return 0;
}