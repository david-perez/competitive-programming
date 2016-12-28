#include <iostream>

using namespace std;

int main() {
    int A, B;
    while (cin >> A >> B)
        cout << (A == B ? A : max(A, B)) << endl;

    return 0;
}