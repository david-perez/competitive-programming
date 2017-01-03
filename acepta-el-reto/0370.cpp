#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T; cin.get();
    while (T--) {
        int a, b;
        scanf("%d-%d", &a, &b);
        int x = min(a, b), y = max(a, b);
        cout << (x % 2 == 0 && x+1 == y ? "SI" : "NO") << endl;
    }

    return 0;
}