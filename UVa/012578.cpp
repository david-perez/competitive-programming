#include <iostream>
#include <cmath> // abs, atan...

using namespace std;

#define PI acos(-1)

int main() {
    int T;
    cin >> T;
    while (T--) {
        double L;
        cin >> L;
        double W = L/10 * 6;
        double R = L/10 * 2;
        double A = PI*R*R;
        printf("%.2f %.2f\n", A, W*L - A);
    }

    return 0;
}