#include <iostream>

using namespace std;

int main() {
    int P, H, O;
    while (cin >> P >> H >> O)
        cout << (H > O - P ? "Hunters win!" : "Props win!") << endl;

    return 0;
}