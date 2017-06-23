#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;

bitset<10000000> bs; // 10^7
vector<ll> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < bs.size(); i++)
        if (bs[i]) {
            for (ll j = i * i; j < bs.size(); j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int main() {
    sieve();
    int k;
    while (cin >> k && k != 0) {
        auto hi = lower_bound(primes.begin(), primes.end(), k);
        if (*hi == k) cout << 0 << endl;
        else {
            auto lo = hi;
            --lo;
            cout << *hi - *lo << endl;
        }
    }

    return 0;
}
