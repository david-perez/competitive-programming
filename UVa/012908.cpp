#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int s;
    while (cin >> s && s != 0) {
        int n = (int) (-1 + sqrt(1 + 8*s)) / 2;
        if (n*(n+1) == 2*s)
            printf("%d %d\n", n+1, n+1);
        else {
            n++;
            printf("%d %d\n", n*(n+1)/2 - s, n);
        }
    }

    return 0;
}