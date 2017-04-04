#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        cout << (N % 2 == 0 ? N/2 : (N-1)/2) << endl;
    }

    return 0;
}