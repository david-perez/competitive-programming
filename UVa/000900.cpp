#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll f[51];
    f[1] = 1;
    f[2] = 2;
    for (int n = 3; n <= 50; n++)
        f[n] = f[n-1] + f[n-2];

    int n;
    while (cin >> n && n != 0)
        cout << f[n] << endl;
    
    return 0;
}
