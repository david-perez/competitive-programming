#include <iostream>

using namespace std;

int main() {
    int a[6];
    int b[6];
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 6; i++)
            cin >> a[i];
        for (int i = 0; i < 6; i++)
            cin >> b[i];

        bool ok = true;
        int sum = a[0] + b[0];
        for (int i = 1; i < 6; i++)
            if (a[i] + b[i] != sum) {
                ok = false;
                break;
            }

        cout << (ok ? "SI" : "NO") << endl;
    }
}
