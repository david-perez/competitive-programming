#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        char c;
        int n, m, p;
        cin >> c >> n >> m;
        if (c == 'r' || c == 'Q') p = min(n, m);
        else if (c == 'k') {
            p = n*m / 2;
            if (n * m % 2 != 0) p++;
        } else {
            int a = min(n, m) / 2;
            if (min(n, m) % 2 != 0) a++;

            int b = max(n, m) / 2;
            if (max(n, m) % 2 != 0) b++;

            p = a * b;
        }
        cout << p << endl;
    }

    return 0;
}