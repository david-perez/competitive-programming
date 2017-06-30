#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        bool ok = true;
        int x, y, d;
        cin >> x >> y;
        d = abs(x - y);
        n--;
        while (n--) {
            cin >> x >> y;
            if (d != abs(x - y)) ok = false;
        }

        cout << (ok ? "yes" : "no") << endl;

        if (T > 0) cout << endl;
    }

    return 0;
}
