#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case %d: ", t);

        double d, v, u;
        cin >> d >> v >> u;
        if (u == 0 || v == 0 || u <= v) {
            cout << "can't determine" << endl;
            continue;
        }

        double t1 = d/u;
        double t2 = d/sqrt(u*u - v*v);
        printf("%.3f\n", t2 - t1);
    }

    return 0;
}