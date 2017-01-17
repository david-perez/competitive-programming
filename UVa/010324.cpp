#include <iostream>

using namespace std;

int main() {
    string s;
    for (int t = 1; cin >> s; t++) {
        int n;
        cin >> n;

        printf("Case %d:\n", t);
        while (n--) {
            int i, j;
            cin >> i >> j;

            bool b = true;
            int k = min(i, j);
            char c = s[k];
            while (k <= max(i, j)) {
                if (s[k] != c) {
                    b = false;
                    break;
                }
                k++;
            }

            cout << (b ? "Yes" : "No") << endl;
        }
    }

    return 0;
}