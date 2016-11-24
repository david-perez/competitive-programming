#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b && !(a < 0 || b < 0))
        cout << 2*(a+b) << endl;

	return 0;
}
