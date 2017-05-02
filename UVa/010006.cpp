#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;

bitset<65000> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < bs.size(); i++)
        if (bs[i])
            for (int j = i * i; j < bs.size(); j += i) bs[j] = 0;
}

int pwr(ll base, ll n, int mod) {
    ll ans = 1;
    while (n) {
        if (n % 2 == 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        n /= 2;
    }
    return ans;
}

void precompute() {
    sieve();
    for (int n = 2; n < 65000; n++)
        if (!bs[n]) {
            bool ok = true;
            for (int a = 2; a < n && ok; a++)
                ok = pwr(a, n, n) == a;
            if (ok) cout << n << endl;
        }
}

int main() {
    // precompute();
    int n, carmichael[] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};
    while (cin >> n && n != 0) {
        if (binary_search(carmichael, carmichael + 15, n))
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);
    }

    return 0;
}
