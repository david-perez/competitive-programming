#include <iostream>

using namespace std;

int dist(int u, int v) {
    return (u - v + 40) % 40;
}

int main() {
    int p, x, y, z;
    while (cin >> p >> x >> y >> z && !(p == 0 && x == 0 && y == 0 && z == 0))
        cout << 9 * (120 + dist(p, x) + dist(y, x) + dist(y, z)) << endl;

    return 0;
}
