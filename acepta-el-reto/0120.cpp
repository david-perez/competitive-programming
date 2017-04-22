#include <iostream>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k && !(n == 0 && k == 0))
        cout << (n*n*n + n) / 2 + (k-1) * n << endl;

    return 0;
}