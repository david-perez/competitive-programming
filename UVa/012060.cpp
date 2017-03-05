#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int len(int x) {
    int ret = 0;
    while (x) {
        x /= 10;
        ret++;
    }
    return ret;
}

int main() {
    int n;
    for (int t = 1; cin >> n && n != 0; t++) {
        printf("Case %d:\n", t);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
        }

        int g = gcd(abs(sum), n);
        int b = sum / g;
        int c = n / g;

        if (c == 1) {
            if (b < 0) cout << "- ";
            cout << abs(b) << endl;
        } else if (abs(b) < c) {
            int lc = len(c), lb = len(b);
            printf("%*d\n", lc - lb + (b < 0 ? 2 : 0) + lb, abs(b));
            if (b < 0) cout << "- ";
            cout << string(lc, '-') << endl;
            if (b < 0) cout << "  ";
            cout << c << endl;
        } else {
            int a = (abs(b) / c) * (b < 0 ? -1 : 1);
            b = abs(b) % c;
            int la = len(a), lc = len(c);
            printf("%*d\n", (a < 0 ? 2 : 0) + la + lc, b);
            if (a < 0) cout << "- ";
            cout << abs(a) << string(lc, '-') << endl;
            printf("%*d\n", (a < 0 ? 2 : 0) + la + lc, c);
        }
    }

    return 0;
}