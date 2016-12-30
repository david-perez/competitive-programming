#include <iostream>
#include <cmath>

using namespace std;

#define PI acos(-1)

int A, B;
double F(double theta) {
    return A*sin(theta) + B*cos(theta);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> A >> B;

        double x, C = (double) A / B;
        if (A == 0 && B == 0)
            x = 0;
        else if (B == 0)
            if (F(PI/2) > 0) x = PI/2;
            else x = PI + PI/2;
        else if (atan(C) >= 0 && F(atan(C)) > 0)
            x = atan(C);
        else if (F(atan(C) + PI) > 0)
            x = atan(C) + PI;
        else
            x = atan(C) + 2*PI;

        printf("%.2f %.2f\n", x, F(x));
    }

    return 0;
}