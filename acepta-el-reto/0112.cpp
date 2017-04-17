#include <iostream>

using namespace std;

int main() {
    int d, v, t;
    while (cin >> d >> v >> t && !(d == 0 && v == 0 && t == 0)) {
        if (d <= 0 || v <= 0 || t <= 0) {
            cout << "ERROR" << endl;
            continue;
        }

        if (18*d <= 5*t*v) cout << "OK" << endl;
        else if (3*d < t*v) cout << "MULTA" << endl;
        else cout << "PUNTOS" << endl;
    }

    return 0;
}
