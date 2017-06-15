#include <iostream>

using namespace std;

uint readIP() {
    uint d3, d2, d1, d0;
    scanf("%u.%u.%u.%u", &d3, &d2, &d1, &d0);
    return (d3 << 24) | (d2 << 16) | (d1 << 8) | d0;
}

void printIP(uint n) {
    printf("%u.%u.%u.%u\n", (n >> 24) & 0xff, (n >> 16) & 0xff, (n >> 8) & 0xff, n & 0xff);
}

int main() {
    int m;
    while (cin >> m) {
        uint mask = -1, a = readIP();
        m--;
        while (m--) {
            uint b = readIP();
            b ^= a;
            if (b == 0) continue; // a == b, no need to expand subnet
            b = __builtin_clz(b);
            uint n = b == 0 ? -1 : (1 << (32 - b)) - 1;
            mask &= ~n;
        }

        printIP(a & mask);
        printIP(mask);
    }

    return 0;
}
