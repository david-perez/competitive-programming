#include <iostream>

using namespace std;

int main() {
    int N;
    for (int t = 1; cin >> N && N != 0; t++) {
        int reasons = 0, treats = 0;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x == 0) treats++;
            else reasons++;
        }

        printf("Case %d: %d\n", t, reasons - treats);
    }

    return 0;
}