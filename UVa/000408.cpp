#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int STEP, MOD;
    while (cin >> STEP >> MOD)
        printf("%10d%10d    %s\n\n", STEP, MOD, gcd(STEP, MOD) == 1 ? "Good Choice" : "Bad Choice");

    return 0;
}