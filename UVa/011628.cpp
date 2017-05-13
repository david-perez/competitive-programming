#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        ll sum = 0, p[n];
        for (int j = 0; j < n; j++)
            for (int i = 1; i <= m; i++)
                if (i == m) {
                    cin >> p[j];
                    sum += p[j];
                } else {
                    int x;
                    cin >> x;
                }
        
        for (int j = 0; j < n; j++) {
            ll g = gcd(p[j], sum);
            printf("%lld / %lld\n", p[j] / g, sum / g);
        }
    }
    
    return 0;
}
