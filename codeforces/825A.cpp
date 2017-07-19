#include <iostream>

using namespace std;

int main() {
    int n, o = 0, m = 0;
    cin >> n; cin.get();
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '1') m++;
        else {
            o = 10*o + m;
            m = 0;
        }
    }

    cout << 10*o + m << endl;

    return 0;
}
