#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double Tn;
    while (cin >> Tn && Tn != 0) {
        int n = (-1 + sqrt(1 + 8*Tn)) / 2;
        printf("%d %d\n", n, (int) Tn - n*(n+1) / 2);
    }
    
    return 0;
}
