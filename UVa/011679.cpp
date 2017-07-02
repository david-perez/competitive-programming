#include <iostream>

using namespace std;

int main() {
    int B, N;
    while (cin >> B >> N && !(B == 0 && N == 0)) {
        int b[B];
        for (int i = 0; i < B; i++) cin >> b[i];
        while (N--) {
            int D, C, V;
            cin >> D >> C >> V;
            D--, C--;
            b[D] -= V;
            b[C] += V;
        }

        bool ok = true;
        for (int i = 0; i < B; i++) if (b[i] < 0) ok = false;
        cout << (ok ? "S" : "N") << endl;
    }

    return 0;
}
