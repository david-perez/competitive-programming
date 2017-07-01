#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll fib[51];
    fib[1] = 2; fib[2] = 3;
    for (int i = 3; i < 51; i++)
        fib[i] = fib[i-2] + fib[i-1];

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n;
        cin >> n;
        printf("Scenario #%d:\n%lld\n\n", t, fib[n]);
    }

    return 0;
}
