#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int evens = 0;
        while (n--) {
            int x;
            cin >> x;
            if (x % 2 == 0) evens++;
        }

        cout << evens << endl;
    }

    return 0;
}