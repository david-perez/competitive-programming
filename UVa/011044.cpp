#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << (((n-2)/3) + ((n-2)%3 == 0 ? 0 : 1)) * (((m-2)/3) + ((m-2)%3 == 0 ? 0 : 1)) << endl;
    }
    return 0;
}