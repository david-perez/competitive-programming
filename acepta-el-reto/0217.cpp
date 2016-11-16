#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0)
        cout << (n % 2 == 1 ? "IZQUIERDA" : "DERECHA") << endl;

    return 0;
}