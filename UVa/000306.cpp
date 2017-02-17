#include <iostream>

using namespace std;

int main() {
    int n, a[200], cycle[200];
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }

        for (int i = 0; i < n; i++) {
            int t = 1;
            int p = a[i];

            while (p != i) {
                t++;
                p = a[p];
            }

            cycle[i] = t; // after t iterations, a[i] returns to pos i
        }

        int k;
        while (cin >> k && k != 0) {
            cin.get();
            string in;
            getline(cin, in);

            if (in.size() < n) {
                string spaces(n - in.size(), ' ');
                in += spaces;
            }

            char out[200];
            for (int i = 0; i < n; i++) {
                int c = k % cycle[i], p = i;
                while (c--)
                    p = a[p];
                out[p] = in[i];
            }

            cout << string(out, n) << endl;
        }
        cout << endl;
    }

    return 0;
}