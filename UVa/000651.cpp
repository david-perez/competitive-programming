#include <iostream>

using namespace std;

int main() {
    double sol[100000];
    sol[1] = 1;
    for (int n = 2; n < 100000; n++) sol[n] = sol[n-1] + 1.0/n;

    cout << "# Cards Overhang" << endl;
    int n;
    while (cin >> n)
        printf("%*d     %.3f\n", 5, n, 0.5 * sol[n]);

    return 0;
}
