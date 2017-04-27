#include <iostream>

using namespace std;

int main() {
    int d[13], f[13];
    d[0] = 1, d[1] = 0;
    f[0] = 1, f[1] = 1;
    for (int n = 2; n <= 12; n++) {
        d[n] = (n-1) * (d[n-1] + d[n-2]);
        f[n] = n * f[n-1];
    }
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        printf("%d/%d\n", d[n], f[n]);
    }
    
    return 0;
}
