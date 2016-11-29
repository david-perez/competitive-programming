#include <iostream>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b && !(a == 0 && b == 0))
        printf("%.1f\n", a * (double) b/2);

    return 0;
}