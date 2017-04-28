#include <iostream>

using namespace std;

int main() {
    int prev;
    while (cin >> prev && prev != -1) {
        int KM = 0, km = 0;
        int M = 0, m = 0, next;
        while (cin >> next && next != -1) {
            km++;
            if (next == prev) m++;
            else {
                if (m > M) {
                    M = max(M, m);
                    KM = km - 1 - m;
                }
                m = 0;
                prev = next;
            }
        }

        if (m > M) {
            M = max(M, m);
            KM = km - m;
        }

        if (M == 0) cout << "HOY NO COMEN" << endl;
        else printf("%d %d\n", KM, M);
    }

    return 0;
}
