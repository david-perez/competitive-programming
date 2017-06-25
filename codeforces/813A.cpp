#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int S = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        S += ai;
    }

    int m;
    cin >> m;
    bool ok = false;
    int T = 100000;
    for (int j = 0; j < m; j++) {
        int lj, rj;
        cin >> lj >> rj;
        if (!ok && S <= rj) {
            ok = true;
            T = max(S, lj);
        }
    }

    cout << (ok ? T : -1) << endl;

    return 0;
}
