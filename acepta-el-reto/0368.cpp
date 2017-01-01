#include <iostream>

using namespace std;

int main() {
    int h, c;
    while (cin >> h >> c && !(h == 0 && c == 0)) {
        int d = h / c;
        if (h % c > 0)
            d++;
        cout << 10*d << endl;
    }

    return 0;
}