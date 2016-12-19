#include <iostream>

using namespace std;

uint clear_msb(uint n) {
    uint mask = n;
    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;
    mask = mask >> 1;

    return n & mask;
}

int main() {
    int n;
    while (cin >> n && n != 0)
        if (n == 1 || n == 2) cout << n << endl;
        else cout << 2 * clear_msb(n) << endl;

    return 0;
}