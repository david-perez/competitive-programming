#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        int sum = 0;
        for (int i = 1; i <= sqrt(N); i++)
            if (N % i == 0) {
                if (i % K != 0) sum += i;
                if (i*i != N && N/i % K != 0) sum += N/i;
            }

        cout << sum << endl;
    }

    return 0;
}
