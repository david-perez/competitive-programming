#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll dp[41];
    dp[1] = 1; dp[2] = 5; dp[3] = 11;
    for (int n = 4; n <= 40; n++)
        dp[n] = dp[n-1] + 4*dp[n-2] + 2*dp[n-3];

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}