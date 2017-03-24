#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (n % 3 == 1 ? "NO" : "YES") << endl;
    }

    return 0;
}