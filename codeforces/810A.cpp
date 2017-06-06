#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        s += ai;
    }

    double m = (n*(k - 0.5) - s) / (0.5);
    cout << max(0, (int) ceil(m)) << endl;

    return 0;
}
