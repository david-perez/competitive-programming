#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int n;
    while (cin >> n && n != 0) {
        ll s = 0, r;
        cin >> r;
        while (n-- > 1) {
            s += abs(r);
            ll x;
            cin >> x;
            r += x;
        }

        cout << s << endl;
    }

    return 0;
}
