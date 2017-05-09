#include <iostream>
#include <cmath>

using namespace std;

double log10(double n) {
    return log(n) / log(10);
}

int main() {
    long long n, k;
    while (cin >> n >> k) {
        double d = 0;
        for (int i = 0; i < k; i++)
            d += log10(n-i) - log10(i+1);

        cout << (int) floor(d) + 1 << endl;
    }
}
