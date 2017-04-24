#include <iostream>

using namespace std;

int main() {
    int L[31], U[31], n;
    L[1] = U[1] = 1; // L[n] = number of safe stacks of size n where the top block is lead.
    L[2] = U[2] = 2; // U[n] = number of safe stacks of size n where the top block is uranium.
    for (n = 3; n <= 30; n++) {
        L[n] = U[n-1] + L[n-1];
        U[n] = L[n-1] + L[n-2];
    }

    while (cin >> n && n != 0)
        cout << (1 << n) - U[n] - L[n] << endl;

    return 0;
}
