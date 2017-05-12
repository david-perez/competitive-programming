#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int r[5001];
    for (int n = 1; n <= 5000; n++) {
        bitset<10> b;
        r[n] = 1;
        int m = n;
        while (m) {
            if (b[(m % 10) - 1]) {
                r[n] = 0;
                break;
            } else {
                b[(m % 10) - 1] = 1;
                m /= 10;
            }
        }

        r[n] += r[n-1];
    }

    int N, M;
    while (cin >> N >> M)
        cout << r[M] - r[N-1] << endl;

    return 0;
}
