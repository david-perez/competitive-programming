#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int a[5];
    while (T--) {
        for (int i = 0; i < 5; i++)
            cin >> a[i];

        bool scala = true;
        for (int i = 0; i < 4; i++)
            scala &= a[i] + 1 == a[i+1];

        cout << (scala ? 'Y' : 'N') << endl;
    }
}