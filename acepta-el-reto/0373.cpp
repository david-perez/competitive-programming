#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        cout << 6*N*N - 12*N + 8 << endl;
    }

    return 0;
}