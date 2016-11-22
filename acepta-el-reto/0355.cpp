#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if ((N % 4 == 0 && N % 100 != 0) || (N % 100 == 0 && N % 400 == 0)) cout << 29 << endl;
        else cout << 28 << endl;
    }
}
