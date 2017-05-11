#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int x;
ll memo[25][145];

ll gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll f(int dl, int score) {
    if (dl == 0) {
        if (score >= x) return 1;
        else return 0;
    }

    if (memo[dl][score] != -1) return memo[dl][score];

    memo[dl][score] = 0;
    for (int v = 1; v <= 6; v++)
        memo[dl][score] += f(dl - 1, score + v);

    return memo[dl][score];
}

int main() {
    int n;
    while (cin >> n >> x && !(n == 0 && x == 0)) {
        for (int dl = 0; dl <= n; dl++)
            for (int score = 0; score <= 6*n; score++)
                memo[dl][score] = -1;

        ll num = f(n, 0);
        ll den = pow(6, n);
        ll g = gcd(num, den);
        num /= g, den /= g;
        if (den == 1) cout << num << endl;
        else printf("%lld/%lld\n", num, den);
    }
    
    return 0;
}
