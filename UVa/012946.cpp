#include <iostream>
#include <complex>
#include <bitset>

using namespace std;

int main() {
    int p;
    while (cin >> p) {
        bitset<32> b = bitset<32>(p);

        complex<int> g = 0;
        complex<int> cf = complex<int>(0, 1) - 1;
        complex<int> pow = 1;
        for (int k = 0; k < 32; k++) {
            g += ((int) b[k]) * pow;
            pow *= cf;
        }

        printf("%d %d\n", g.real(), g.imag());
    }

    return 0;
}