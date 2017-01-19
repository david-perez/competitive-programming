#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, K, P;
        cin >> N >> K >> P;

        printf("Case %d: %d\n", t, ((K-1+P) % N) + 1);
    }
}